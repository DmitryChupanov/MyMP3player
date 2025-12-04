/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
#include "fatfs.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "MyVS1053b.h"
#include "MySPI.h"
#include "MyCommonFCs.h"
#include "SPI_ILI9341.h"
#include "Buttons.h"
#include "xpt2046.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

SD_HandleTypeDef hsd1;

SPI_HandleTypeDef hspi4;

osThreadId defaultTaskHandle;
osThreadId myTask02Handle;
osThreadId myTask03Handle;
/* USER CODE BEGIN PV */

uint8_t SPI_RX_DATA[8] = {};
uint8_t SPI_TX_DATA[8] = {vs_READ,vs_MODE,0,0}; //vs_STATUS vs_MODE
uint8_t PlaybackBuf[_MAX_SS] = {};
FRESULT SdOpRes;
FRESULT fr;     /* Return value */
FRESULT fileReadResult;		// Результат выполнения фуекции чтения файла
UINT ByteWriten = 0;
SCI_StatusTypedef SCI_Status = SCI_Ok;
uint16_t SciRegContent = 0;
uint32_t BtnPlusCounter = 0;
uint32_t BtnMinusCounter = 0;
uint32_t BtnModeCounter = 0;
BtnStateTypedef BtnPlusState;
BtnStateTypedef BtnMinusState;
BtnStateTypedef BtnModeState = BtnReset;
BtnStateTypedef BtnModeStateOld = BtnReset;
//uint16_t i,j;
extern uint16_t TFT9341_WIDTH;
extern uint16_t TFT9341_HEIGHT;

uint8_t FrameBufer[MyDisplWidth * MyDisplHeight * 2] = {};

	// Переменные для тачскрина
  uint8_t flag_press = 1;
  uint32_t time_press = 0;
  uint16_t x_toch = 0;
  uint16_t y_toch = 0;
	
	RequestsTypedef FrBufSendReq = NoReq; // Флаг запроса отправки кадрового буфера
	RequestsTypedef NextTrackReq = NoReq; // Флаг запроса следующего трека
	RequestsTypedef PauseReq = NoReq; 		// Флаг запроса паузы
	RequestsTypedef PlayPauseDrawReq = NoReq; // Флаг запроса отрисовки кнопки Play/Pause
	uint32_t PauseReqDelay = 1500;
	RequestsTypedef VolChangeReq = NoReq; // Флаг запроса изменения громкости
	RequestsTypedef VolDrawReq = NoReq; // Флаг запроса отрисовки полосы громкости
	RequestsTypedef PrintPageReq = ThereIsReq; // Флаг запроса печати новой страницы на экран
	RequestsTypedef HighlightingReq = ThereIsReq; // Флаг запроса выделения строки на экране
	RequestsTypedef EqualizerChangeReq = NoReq; 	// Флаг запроса изменения параметров эквалайзера
	
	uint8_t VolumeCurrent = 30; // Текущее значение громкости
	uint32_t CurrentPlayFile = 0;		// Порядковый номер Текущего воспроизводимого файла

	FilManParamTypedef FilManParam={
		.MountState = CardIsUnmounted,
		.FrBuf = FrameBufer,
		.FirstPrintedItem = 0,
		.HighlightedItemNumber = 0,
		.OpenDirState = DirClosed,
		.RreadDirState = DirNotRread,
		.FileOpenState = FileNotOpened,
		.FileSize = 0,
		.FileSizeRead = 0,
		.PlaybackBufBytesFilled = 0,
		.BytesRead = 0,
		.PlaybackBufTxIndex = 0,
		.Screen = MainScreen,
		.DrawHF_GainBarReq = NoReq, 	// Флаг запроса печати бара усиления высоких частот
		.DrawHF_BorderBarReq = NoReq, // Флаг запроса печати бара границы высоких частот
		.DrawLF_GainBarReq = NoReq,   // Флаг запроса печати бара усиления низких частот
		.DrawLF_BorderBarReq = NoReq, // Флаг запроса печати бара границы низких частот
		.ProgressDrawReq= NoReq, 			// Флаг запроса отрисовки полосы воспроизведения файла
		
	};

	uint32_t DirItemsCounter = 0;
	uint8_t HF_Gain = 0x01;
	uint8_t HF_Border =0x04;
	uint8_t LF_Gain = 0x01;
	uint8_t LF_Border = 0x08;
	uint32_t ProgressTimer = 5000;
	uint8_t DisplayState = 1;
	uint8_t DisplDelay = 0;
	RequestsTypedef DisplOnOffReq = NoReq; 	// Флаг запроса вкл/выкл дисплея
	
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SDMMC1_SD_Init(void);
static void MX_SPI4_Init(void);
void StartDefaultTask(void const * argument);
void StartTask02(void const * argument);
void StartTask03(void const * argument);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SDMMC1_SD_Init();
  MX_FATFS_Init();
  MX_SPI4_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 2048);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of myTask02 */
  osThreadDef(myTask02, StartTask02, osPriorityIdle, 0, 512);
  myTask02Handle = osThreadCreate(osThread(myTask02), NULL);

  /* definition and creation of myTask03 */
  osThreadDef(myTask03, StartTask03, osPriorityIdle, 0, 128);
  myTask03Handle = osThreadCreate(osThread(myTask03), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Supply configuration update enable
  */
  HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);
  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}
  /** Macro to configure the PLL clock source
  */
  __HAL_RCC_PLL_PLLSOURCE_CONFIG(RCC_PLLSOURCE_HSI);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 25;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_3;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV1;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SDMMC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SDMMC1_SD_Init(void)
{

  /* USER CODE BEGIN SDMMC1_Init 0 */

  /* USER CODE END SDMMC1_Init 0 */

  /* USER CODE BEGIN SDMMC1_Init 1 */

  /* USER CODE END SDMMC1_Init 1 */
  hsd1.Instance = SDMMC1;
  hsd1.Init.ClockEdge = SDMMC_CLOCK_EDGE_RISING;
  hsd1.Init.ClockPowerSave = SDMMC_CLOCK_POWER_SAVE_DISABLE;
  hsd1.Init.BusWide = SDMMC_BUS_WIDE_4B;
  hsd1.Init.HardwareFlowControl = SDMMC_HARDWARE_FLOW_CONTROL_DISABLE;
  hsd1.Init.ClockDiv = 10;
  /* USER CODE BEGIN SDMMC1_Init 2 */

  /* USER CODE END SDMMC1_Init 2 */

}

/**
  * @brief SPI4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI4_Init(void)
{

  /* USER CODE BEGIN SPI4_Init 0 */

  /* USER CODE END SPI4_Init 0 */

  /* USER CODE BEGIN SPI4_Init 1 */

  /* USER CODE END SPI4_Init 1 */
  /* SPI4 parameter configuration*/
  hspi4.Instance = SPI4;
  hspi4.Init.Mode = SPI_MODE_MASTER;
  hspi4.Init.Direction = SPI_DIRECTION_2LINES;
  hspi4.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi4.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi4.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi4.Init.NSS = SPI_NSS_SOFT;
  hspi4.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_64;
  hspi4.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi4.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi4.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi4.Init.CRCPolynomial = 0x0;
  hspi4.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
  hspi4.Init.NSSPolarity = SPI_NSS_POLARITY_LOW;
  hspi4.Init.FifoThreshold = SPI_FIFO_THRESHOLD_01DATA;
  hspi4.Init.TxCRCInitializationPattern = SPI_CRC_INITIALIZATION_ALL_ZERO_PATTERN;
  hspi4.Init.RxCRCInitializationPattern = SPI_CRC_INITIALIZATION_ALL_ZERO_PATTERN;
  hspi4.Init.MasterSSIdleness = SPI_MASTER_SS_IDLENESS_00CYCLE;
  hspi4.Init.MasterInterDataIdleness = SPI_MASTER_INTERDATA_IDLENESS_00CYCLE;
  hspi4.Init.MasterReceiverAutoSusp = SPI_MASTER_RX_AUTOSUSP_DISABLE;
  hspi4.Init.MasterKeepIOState = SPI_MASTER_KEEP_IO_STATE_DISABLE;
  hspi4.Init.IOSwap = SPI_IO_SWAP_DISABLE;
  if (HAL_SPI_Init(&hspi4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI4_Init 2 */

  /* USER CODE END SPI4_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, TFT_Brightnes_Pin|TOUCH_CS_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, TFT_CS_Pin|XCS_Pin|XDCS_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, TFT_DC_Pin|TFT_RST_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(XRESET_GPIO_Port, XRESET_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin : T_IRQ_Pin */
  GPIO_InitStruct.Pin = T_IRQ_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(T_IRQ_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : TFT_Brightnes_Pin */
  GPIO_InitStruct.Pin = TFT_Brightnes_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(TFT_Brightnes_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : TFT_CS_Pin */
  GPIO_InitStruct.Pin = TFT_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(TFT_CS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : TFT_DC_Pin TFT_RST_Pin XCS_Pin XDCS_Pin */
  GPIO_InitStruct.Pin = TFT_DC_Pin|TFT_RST_Pin|XCS_Pin|XDCS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : DREQ_Pin */
  GPIO_InitStruct.Pin = DREQ_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(DREQ_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : XRESET_Pin */
  GPIO_InitStruct.Pin = XRESET_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
  HAL_GPIO_Init(XRESET_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : BtnPlus_Pin */
  GPIO_InitStruct.Pin = BtnPlus_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(BtnPlus_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : BtnMinus_Pin BtnMode_Pin */
  GPIO_InitStruct.Pin = BtnMinus_Pin|BtnMode_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pin : TOUCH_CS_Pin */
  GPIO_InitStruct.Pin = TOUCH_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(TOUCH_CS_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
//__STATIC_INLINE void DelayMicro(uint32_t __IO micros)
//{
//  micros *=(SystemCoreClock/1000000)/5;
//  while(micros--);
//}
/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN 5 */
	SPI2InitSimplexTransmitter(0);
	TFT9341_ini(MyDisplWidth, MyDisplHeight);
	TFT9341_SetTextColor(TFT9341_BLUE);
  TFT9341_SetBackColor(TFT9341_BLACK);
  TFT9341_SetFont(&Font18);
	
	if(FilManParam.MountState == CardIsUnmounted)
	{
		if(f_mount(&SDFatFS, SDPath,1) == FR_OK)
		{
			FilManParam.MountState = CardIsMounted;
		}
		else
		{
			f_mount(NULL, SDPath,1);
			FilManParam.MountState = CardIsUnmounted;
			TFT9341_StringToBuf(FrameBufer,0,0 ,"Карта не смонтирована");
		}
	}
	
	GetItemNumberInThisDir(&FilManParam);
	if(PrintPageReq == ThereIsReq) 
	{
		FileManager(&FilManParam); // Печать страницы с именами файлов на экран
		PrintPageReq = NoReq; 																				 // Сброс Флага запроса печати новой страницы на экран
	}
	//--------------------------------------------------- Отрисовка экрана ---------------------------------------------
	DrawPictureToBuf(FrameBufer, 0, 279, PreviousBtn, 40, 40); 					// Кнопка Previous
	DrawPictureToBuf(FrameBufer, 50, 279, PauseBtn, 40, 40);						// Кнопка Pause
	DrawPictureToBuf(FrameBufer, 100, 279, NextBtn, 40, 40);  					// Кнопка Next
	DrawPictureToBuf(FrameBufer, 150, 279, VolMinusBtn, 40, 40);  			// Кнопка VolMinus
	DrawPictureToBuf(FrameBufer, 199, 279, VolPlusBtn, 40, 40);  				// Кнопка VolPlus
	DrawVolToFrameBuf(FrameBufer, 165, 270, TFT9341_GREEN, TFT9341_BLACK, (float) VolumeCurrent);	// Полоса громкости
	//PrintScrolLine(FrameBufer, 222, 1, 216, TFT9341_BLUE, TFT9341_BLACK);	// Отрисовка полосы прокрутки
	//DrawPictureToBuf(FrameBufer, 155,230, PropertiesBtn, 30, 30);

	
	
	FrBufSendReq = ThereIsReq; // Запрос отправки на дисплей кадрового буфера
	//TFT9341_SendFrameBuf(FrameBufer, 0, 0, TFT9341_WIDTH-1, TFT9341_HEIGHT-1);
	//-------------------------------------------------------------------------------------------------------------------
		
		/* Infinite loop */
		for(;;)
		{
			if(DisplDelay > 0) DisplDelay--;
			
			if(PrintPageReq == ThereIsReq)
			{
				FileManager(&FilManParam); // Печать страницы с именами файлов на экран
				PrintPageReq = NoReq;
				FrBufSendReq = ThereIsReq;	// Запрос отправки на дисплей кадрового буфера
			}
			
			if(HighlightingReq == ThereIsReq) // Выделение воспроизводимого файла
			{
				Highlighting(&FilManParam, CurrentPlayFile);
				HighlightingReq = NoReq;
				FrBufSendReq = ThereIsReq;	// Запрос отправки на дисплей кадрового буфера
			}

			if(VolDrawReq) // Отрисовка полосы громкости
			{
				DrawVolToFrameBuf(FrameBufer, 165, 270, TFT9341_GREEN, TFT9341_BLACK, (float) VolumeCurrent);	// Полоса громкости
				FrBufSendReq = ThereIsReq;
				VolDrawReq = NoReq;
			}
			
			if(PlayPauseDrawReq)	// Отрисовка кнопок Play/Pause
			{
				if(PauseReq)
				{
					DrawPictureToBuf(FrameBufer, 50, 279, PlayBtn, 40, 40);											// Кнопка
					FrBufSendReq = ThereIsReq;
				}
				else
				{
					DrawPictureToBuf(FrameBufer, 50, 279, PauseBtn, 40, 40);										// Кнопка
					FrBufSendReq = ThereIsReq;
				}
				PlayPauseDrawReq = NoReq;
			}
			
			if(FilManParam.DrawHF_GainBarReq == ThereIsReq) // Печать бара усиления высоких частот
			{
				DrawBar(FrameBufer,45,36,150,18,0,7, HF_Gain , TFT9341_WHITE, TFT9341_BLACK);
				FilManParam.DrawHF_GainBarReq = NoReq;
				FrBufSendReq = ThereIsReq;
			}
			
			if(FilManParam.DrawHF_BorderBarReq == ThereIsReq) // Печать бара границы высоких частот
			{
				DrawBar(FrameBufer,45,90,150,18,0,15, HF_Border , TFT9341_WHITE, TFT9341_BLACK);
				FilManParam.DrawHF_BorderBarReq = NoReq;
				FrBufSendReq = ThereIsReq;				
			}
			
			if(FilManParam.DrawLF_GainBarReq == ThereIsReq) // Печать бара усиления низких частот
			{
				DrawBar(FrameBufer,45,144,150,18,0,15, LF_Gain , TFT9341_WHITE, TFT9341_BLACK);
				FilManParam.DrawLF_GainBarReq = NoReq;
				FrBufSendReq = ThereIsReq;				
			}
			
			if(FilManParam.DrawLF_BorderBarReq == ThereIsReq) // Печать бара границы низких частот
			{
				DrawBar(FrameBufer,45,197,150,18,0,15, LF_Border , TFT9341_WHITE, TFT9341_BLACK);
				FilManParam.DrawLF_BorderBarReq = NoReq;
				FrBufSendReq = ThereIsReq;				
			}
			
			ProgressTimer++;
			if(FilManParam.ProgressDrawReq == ThereIsReq && ProgressTimer > 5000) // Отрисовка прогресс бара воспроизведения файла
			{
				DrawBar32(FrameBufer,5,264,150,6,0,(float)FilManParam.FileSize, (float)FilManParam.FileSizeRead, TFT9341_WHITE, TFT9341_BLACK);
				FilManParam.ProgressDrawReq = NoReq;
				ProgressTimer = 0;
				FrBufSendReq = ThereIsReq;
			}
			
			
			
			if(FrBufSendReq == ThereIsReq && SPI2_TransferInProcess == 0 && DisplDelay == 0 && DisplayState == 1)
			{
				TFT9341_SendFrameBuf(FrameBufer, 0, 0, TFT9341_WIDTH-1, TFT9341_HEIGHT-1); // Отправка кадрового буфера в дисплей
				FrBufSendReq = NoReq;
			}
			
			
			
			ReadFile(&FilManParam, &CurrentPlayFile);

			osDelay(1);
		}
  /* USER CODE END 5 */
}

/* USER CODE BEGIN Header_StartTask02 */
/**
* @brief Function implementing the myTask02 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask02 */
void StartTask02(void const * argument)
{
  /* USER CODE BEGIN StartTask02 */
	
	//HardReset(VolumeCurrent);
	HardReset(VolumeCurrent,HF_Gain,HF_Border, LF_Gain,LF_Border);
//	ReadSCI_RegV2(vs_VOL, &SciRegContent);
//	ReadSCI_RegV2(vs_MODE, &SciRegContent);
//	ReadSCI_RegV2(vs_STATUS, &SciRegContent);
//	ReadSCI_RegV2(vs_CLOCKF, &SciRegContent);
//	ReadSCI_RegV2(vs_BASS, &SciRegContent);
	SoftReset();


	
  /* Infinite loop */
  for(;;)
  {
		if( ((SPI1->SR & SPI_SR_TXC)!=0)&&((SPI1->SR & SPI_SR_TXP)!=0)&&((DMA1->LISR & DMA_LISR_TCIF0)!=0)&&((DMA1->LISR & DMA_LISR_FEIF0)!=0)&&(PauseReq == NoReq) )
		{
			XCS_Set;
			XCS_Set;
			if((((SPI1->CFG2 & SPI_CFG2_COMM_Msk)>>SPI_CFG2_COMM_Pos) != 0x01)
			|| (((SPI1->CFG1 & SPI_CFG1_MBR_Msk)>>SPI_CFG1_MBR_Pos)!=0x04))	// Если трансмитер находится не в режиме 01: simplex transmitter или делитель не тот
			{
				SPI1InitSimplexTransmitterV2(0x04);		// То перевести его в этот режим
			}
			if((FilManParam.PlaybackBufBytesFilled > 0)&&(DREQ_State == GPIO_PIN_SET))	// Если в буфере есть данные не отправленные на кодек и кодек может принять данные
			{
				if(FilManParam.PlaybackBufBytesFilled > 32)	// Передача куска данных в 32 байта
				{
					XDCS_Reset;
					SPI1_DMA_TransmitV2(&PlaybackBuf[FilManParam.PlaybackBufTxIndex], 32);
					FilManParam.PlaybackBufTxIndex += 32;				// Сдвиг индекса на начало еще не отправленных данных
					FilManParam.PlaybackBufBytesFilled -=32;		// Уменьшение счетчика байт оставшихся в буфере
					while( ((SPI1->SR & SPI_SR_TXC)==0)||((SPI1->SR & SPI_SR_TXP)==0)||((DMA1->LISR & DMA_LISR_TCIF0)==0)||((DMA1->LISR & DMA_LISR_FEIF0)==0) )
					{
						__NOP();
					}
				}
				else
				{
					XDCS_Reset;
					SPI1_DMA_TransmitV2(&PlaybackBuf[FilManParam.PlaybackBufTxIndex], FilManParam.PlaybackBufBytesFilled); // Передача оставшихся данных
					while( ((SPI1->SR & SPI_SR_TXC)==0)||((SPI1->SR & SPI_SR_TXP)==0)||((DMA1->LISR & DMA_LISR_TCIF0)==0)||((DMA1->LISR & DMA_LISR_FEIF0)==0) )
					{
						__NOP();
					}
					FilManParam.PlaybackBufBytesFilled = 0;							// Обнуление количества байт, оставшихся в буфере
				}
				XDCS_Set;
			}
			if((FilManParam.PlaybackBufBytesFilled > 0)&&(DREQ_State == GPIO_PIN_SET))	// Если в буфере есть данные не отправленные на кодек и кодек может принять данные
			{
				if(FilManParam.PlaybackBufBytesFilled > 32)	// Передача куска данных в 32 байта
				{
					XDCS_Reset;
					SPI1_DMA_TransmitV2(&PlaybackBuf[FilManParam.PlaybackBufTxIndex], 32);
					FilManParam.PlaybackBufTxIndex += 32;				// Сдвиг индекса на начало еще не отправленных данных
					FilManParam.PlaybackBufBytesFilled -=32;		// Уменьшение счетчика байт оставшихся в буфере
				}
				else
				{
					XDCS_Reset;
					SPI1_DMA_TransmitV2(&PlaybackBuf[FilManParam.PlaybackBufTxIndex], FilManParam.PlaybackBufBytesFilled); // Передача оставшихся данных
					while( ((SPI1->SR & SPI_SR_TXC)==0)||((SPI1->SR & SPI_SR_TXP)==0)||((DMA1->LISR & DMA_LISR_TCIF0)==0)||((DMA1->LISR & DMA_LISR_FEIF0)==0) )
					{
						__NOP();
					}
					FilManParam.PlaybackBufBytesFilled = 0;							// Обнуление количества байт, оставшихся в буфере
				}
			}
		}
		if(VolChangeReq == ThereIsReq)
		{
			while( ((SPI1->SR & SPI_SR_TXC)==0)||((SPI1->SR & SPI_SR_TXP)==0)||((DMA1->LISR & DMA_LISR_TCIF0)==0)||((DMA1->LISR & DMA_LISR_FEIF0)==0) )
			{
				__NOP();
			}
			WriteSCI_RegV2(vs_VOL, VolumeCurrent, VolumeCurrent);
			VolChangeReq = NoReq;
		}
		
		if(EqualizerChangeReq == ThereIsReq) // Запрос изменения параметров эквалайзера
		{
			while( ((SPI1->SR & SPI_SR_TXC)==0)||((SPI1->SR & SPI_SR_TXP)==0)||((DMA1->LISR & DMA_LISR_TCIF0)==0)||((DMA1->LISR & DMA_LISR_FEIF0)==0) )
			{
				__NOP();
			}
			WriteSCI_Reg16(vs_BASS, (HF_Gain<<TREBLE_AMPLITUDE_pos | HF_Border<<TREBLE_FREQLIMIT_pos|LF_Gain<<BASS_AMPLITUDE_pos | LF_Border)/*0x7A18*/);
			EqualizerChangeReq = NoReq;
//			osDelay(1);
//			ReadSCI_RegV2(vs_BASS, &SciRegContent);
		}
		
    osDelay(1);
  }
  /* USER CODE END StartTask02 */
}

/* USER CODE BEGIN Header_StartTask03 */
/**
* @brief Function implementing the myTask03 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask03 */
void StartTask03(void const * argument)
{
  /* USER CODE BEGIN StartTask03 */
	TOUCH_CS_UNSELECT; // это нужно только если есть тач
	/* Infinite loop */
  for(;;)
  {
		//------------------------------------------------ Кнопки физические -------------------------------------------------
		if(HAL_GPIO_ReadPin(BtnPlus_GPIO_Port, BtnPlus_Pin) == GPIO_PIN_RESET)
			BtnPlusCounter = (BtnPlusCounter < 250)? ++BtnPlusCounter : 250;
		else
			BtnPlusCounter = (BtnPlusCounter > 0)? --BtnPlusCounter : 0;

		if(HAL_GPIO_ReadPin(BtnMinus_GPIO_Port, BtnMinus_Pin) == GPIO_PIN_RESET)
			BtnMinusCounter = (BtnMinusCounter < 250)? ++BtnMinusCounter : 250;
		else
			BtnMinusCounter = (BtnMinusCounter > 0)? --BtnMinusCounter : 0;
		
		if(HAL_GPIO_ReadPin(BtnMode_GPIO_Port, BtnMode_Pin) == GPIO_PIN_RESET)
			BtnModeCounter = (BtnModeCounter < 200)? ++BtnModeCounter : 200;
		else
			BtnModeCounter = (BtnModeCounter > 0)? --BtnModeCounter : 0;
		
		if(BtnPlusCounter == 250) 
		{
			BtnPlusState = BtnSet; 
			BtnPlusCounter = 0; 
			if(VolumeCurrent>=5)
			{
				VolumeCurrent -= 5;
			}
			VolChangeReq = ThereIsReq; // Флаг запроса изменения громкости
			VolDrawReq = ThereIsReq;   // Флаг запроса отрисовки громкости
		}
		if(BtnPlusCounter == 0) BtnPlusState = BtnReset;
		if(BtnMinusCounter == 250) 
		{
			BtnMinusState = BtnSet;
			BtnMinusCounter = 0;
			if(VolumeCurrent < 150)
			{
				VolumeCurrent += 5;
			}
			VolChangeReq = ThereIsReq; // Флаг запроса изменения громкости
			VolDrawReq = ThereIsReq;		// Флаг запроса полоски громкости
		}
		if(BtnMinusCounter == 0) BtnMinusState = BtnReset;
		
		if(BtnModeCounter == 200) BtnModeState = BtnSet;
		if(BtnModeCounter == 0) BtnModeState = BtnReset;
		
		
		
		if((BtnModeState == BtnSet)&&(BtnModeStateOld == BtnReset))
		{
			DisplOnOffReq = ThereIsReq; 	// Флаг запроса вкл/выкл дисплея
		}
		BtnModeStateOld = BtnModeState;
		if(DisplOnOffReq==ThereIsReq && SPI2_TransferInProcess==0 && DisplDelay==0)
		{
			if(DisplayState == 1)
			{
				DisplOff();
				DisplayState = 0;
				DisplDelay = 5;
			}
			else
			{
				DisplOn();
				DisplayState = 1;
				DisplDelay = 120;
			}
			DisplOnOffReq = NoReq; 	// Флаг запроса вкл/выкл дисплея
		}

	//---------------------------- Это тачскрин ------------------------------------------------	
	if(HAL_GPIO_ReadPin(T_IRQ_GPIO_Port, T_IRQ_Pin) == GPIO_PIN_RESET && flag_press && DisplayState == 1) // если нажат тачскрин
  {
	  x_toch = 0;
	  y_toch = 0;

	  TOUCH_CS_UNSELECT;
		ILI9341_TouchGetCoordinates(&x_toch, &y_toch);
		if(ILI9341_TouchGetCoordinates(&x_toch, &y_toch))
	  {
		  flag_press = 0;
	  }
		
		//-------------------------------------------------------- Здесь кнопки тача ---------------------------------------------------
		if(x_toch > 0 && x_toch < 50 && y_toch > 280 && y_toch < 320) // нажатие кнопки пущего трека
		{
			if(CurrentPlayFile > 0)
			{
				CurrentPlayFile--;
				HighlightingReq = ThereIsReq;
			}
			if(CurrentPlayFile < FilManParam.FirstPrintedItem)
			{
				if(FilManParam.FirstPrintedItem >= DisplPrintRows)
					FilManParam.FirstPrintedItem -= DisplPrintRows;
				else
					FilManParam.FirstPrintedItem = 0;
				
				PrintPageReq = ThereIsReq;
			}
			x_toch = 0;
			y_toch = 0;
		}
		else if(x_toch > 102 && x_toch < 140 && y_toch > 280 && y_toch < 320) // если нажата кнопка следующего трека 
	  {
		  //NextTrackReq = ThereIsReq;
			if(CurrentPlayFile < FilManParam.DirItemsNumber-1)
			{
				CurrentPlayFile++;
				HighlightingReq = ThereIsReq;
			}
			if(CurrentPlayFile >= (FilManParam.FirstPrintedItem + DisplPrintRows))
			{
				FilManParam.FirstPrintedItem = CurrentPlayFile;
				PrintPageReq = ThereIsReq;
			}
			x_toch = 0;
			y_toch = 0;
	  }
	  else if(x_toch > 50 && x_toch < 89 && y_toch > 280 && y_toch < 320 && PauseReqDelay == 0) // нажатие кнопки плей Пауза
	  {
			PauseReqDelay = 1500;
			if(PauseReq)
			{
				PauseReq = NoReq; 						 // Флаг запроса паузы
				PlayPauseDrawReq = ThereIsReq; // Флаг запроса отрисовки кнопки Play/Pause
			}
			else
			{
				PauseReq = ThereIsReq; 				 // Флаг запроса паузы
				PlayPauseDrawReq = ThereIsReq; // Флаг запроса отрисовки кнопки Play/Pause
			}
		  x_toch = 0;
			y_toch = 0;
	  }
		else if(x_toch > 208 && x_toch < 237 && y_toch > 280 && y_toch < 320) // нажатие кнопки Vol+
	  {
			if(VolumeCurrent>=5)
			{
				VolumeCurrent -= 5;
			}
			x_toch = 0;
			y_toch = 0;
			VolChangeReq = ThereIsReq; // Флаг запроса изменения громкости
			VolDrawReq = ThereIsReq;   // Флаг запроса отрисовки громкости
		}
		else if(x_toch > 157 && x_toch < 190 && y_toch > 280 && y_toch < 320) // нажатие кнопки Vol-
	  {
			if(VolumeCurrent < 150)
			{
				VolumeCurrent += 5;
			}
			x_toch = 0;
			y_toch = 0;
			VolChangeReq = ThereIsReq; // Флаг запроса изменения громкости
			VolDrawReq = ThereIsReq;		// Флаг запроса полоски громкости
		}
		else if(x_toch > 1 && x_toch < 40 && y_toch > 225 && y_toch < 256) // Выбор страницы Основная/Эквалайзер
		{
			if(FilManParam.Screen == MainScreen)
			{
				FilManParam.Screen = EqualizerScreen;
				
				PrintPageReq = ThereIsReq;	// Запрос отрисовки страницы
				FrBufSendReq = ThereIsReq;	// Запрос отправки на дисплей кадрового буфера
			}
			else
			{
				FilManParam.Screen = MainScreen;
				
				PrintPageReq = ThereIsReq;		// Запрос отрисовки страницы
				HighlightingReq = ThereIsReq; // Выделение воспроизводимого файла
				FrBufSendReq = ThereIsReq;		// Запрос отправки на дисплей кадрового буфера
			}
			x_toch = 0;
			y_toch = 0;
		}
		
		
		if(FilManParam.Screen == MainScreen)
		{
			if(x_toch > 0 && x_toch < 180 && y_toch > 0 && y_toch < 16) // Строка 0
			{
				CurrentPlayFile = FilManParam.FirstPrintedItem;
				HighlightingReq = ThereIsReq;
				x_toch = 0;
				y_toch = 0;
			}
			else if(x_toch > 0 && x_toch < 180 && y_toch > 20 && y_toch < 34) // Строка 1
			{
				if((FilManParam.FirstPrintedItem+1)<FilManParam.DirItemsNumber)
				{
					CurrentPlayFile = FilManParam.FirstPrintedItem + 1;
					HighlightingReq = ThereIsReq;
				}
				x_toch = 0;
				y_toch = 0;
			}
			else if(x_toch > 0 && x_toch < 180 && y_toch > 38 && y_toch < 52) // Строка 2
			{
				if((FilManParam.FirstPrintedItem+2)<FilManParam.DirItemsNumber)
				{
					CurrentPlayFile = FilManParam.FirstPrintedItem + 2;
					HighlightingReq = ThereIsReq;
				}
				x_toch = 0;
				y_toch = 0;
			}
			else if(x_toch > 0 && x_toch < 180 && y_toch > 56 && y_toch < 70) // Строка 3
			{
				if((FilManParam.FirstPrintedItem+3)<FilManParam.DirItemsNumber)
				{
					CurrentPlayFile = FilManParam.FirstPrintedItem + 3;
					HighlightingReq = ThereIsReq;
				}
				x_toch = 0;
				y_toch = 0;
			}
			else if(x_toch > 0 && x_toch < 180 && y_toch > 74 && y_toch < 88) // Строка 4
			{
				if((FilManParam.FirstPrintedItem+4)<FilManParam.DirItemsNumber)
				{
					CurrentPlayFile = FilManParam.FirstPrintedItem + 4;
					HighlightingReq = ThereIsReq;
				}
				x_toch = 0;
				y_toch = 0;
			}
			else if(x_toch > 0 && x_toch < 180 && y_toch > 92 && y_toch < 106) // Строка 5
			{
				if((FilManParam.FirstPrintedItem+5)<FilManParam.DirItemsNumber)
				{
					CurrentPlayFile = FilManParam.FirstPrintedItem + 5;
					HighlightingReq = ThereIsReq;
				}
				x_toch = 0;
				y_toch = 0;
			}
			else if(x_toch > 0 && x_toch < 180 && y_toch > 110 && y_toch < 124) // Строка 6
			{
				if((FilManParam.FirstPrintedItem+6)<FilManParam.DirItemsNumber)
				{
					CurrentPlayFile = FilManParam.FirstPrintedItem + 6;
					HighlightingReq = ThereIsReq;
				}
				x_toch = 0;
				y_toch = 0;
			}
			else if(x_toch > 0 && x_toch < 180 && y_toch > 128 && y_toch < 142) // Строка 7
			{
				if((FilManParam.FirstPrintedItem+7)<FilManParam.DirItemsNumber)
				{
					CurrentPlayFile = FilManParam.FirstPrintedItem + 7;
					HighlightingReq = ThereIsReq;
				}
				x_toch = 0;
				y_toch = 0;
			}
			else if(x_toch > 0 && x_toch < 180 && y_toch > 146 && y_toch < 160) // Строка 8
			{
				if((FilManParam.FirstPrintedItem+8)<FilManParam.DirItemsNumber)
				{
					CurrentPlayFile = FilManParam.FirstPrintedItem + 8;
					HighlightingReq = ThereIsReq;
				}
				x_toch = 0;
				y_toch = 0;
			}
			else if(x_toch > 0 && x_toch < 180 && y_toch > 164 && y_toch < 178) // Строка 9
			{
				if((FilManParam.FirstPrintedItem+9)<FilManParam.DirItemsNumber)
				{
					CurrentPlayFile = FilManParam.FirstPrintedItem + 9;
					HighlightingReq = ThereIsReq;
				}
				x_toch = 0;
				y_toch = 0;
			}
			else if(x_toch > 0 && x_toch < 180 && y_toch > 182 && y_toch < 196) // Строка 10
			{
				if((FilManParam.FirstPrintedItem+10)<FilManParam.DirItemsNumber)
				{
					CurrentPlayFile = FilManParam.FirstPrintedItem + 10;
					HighlightingReq = ThereIsReq;
				}
				x_toch = 0;
				y_toch = 0;
			}
			else if(x_toch > 0 && x_toch < 180 && y_toch > 200 && y_toch < 214) // Строка 11
			{
				if((FilManParam.FirstPrintedItem+11)<FilManParam.DirItemsNumber)
				{
					CurrentPlayFile = FilManParam.FirstPrintedItem + 11;
					HighlightingReq = ThereIsReq;
				}
				x_toch = 0;
				y_toch = 0;
			}
			else if(x_toch > 200 && x_toch < 240 && y_toch > 0 && y_toch < 18) // нажатие стрелки прокрутки вверх
			{
				if(FilManParam.FirstPrintedItem >= DisplPrintRows)
					FilManParam.FirstPrintedItem -= DisplPrintRows;
				else
					FilManParam.FirstPrintedItem = 0;
				PrintPageReq = ThereIsReq;
				HighlightingReq = ThereIsReq;
				x_toch = 0;
				y_toch = 0;
			}
			else if(x_toch > 200 && x_toch < 240 && y_toch > 190 && y_toch < 220) // нажатие стрелки прокрутки вниз
			{
				if((FilManParam.FirstPrintedItem + DisplPrintRows)< FilManParam.DirItemsNumber)
				{
					FilManParam.FirstPrintedItem += DisplPrintRows;
					PrintPageReq = ThereIsReq;
					HighlightingReq = ThereIsReq;
				}
				x_toch = 0;
				y_toch = 0;
			}
		}
		//**************** Если выбрана страница эквалайзера *****************
		else if(FilManParam.Screen == EqualizerScreen)
		{
			if(x_toch > 200 && x_toch < 225 && y_toch > 36 && y_toch < 54) // + Усиление высоких частот
			{
				if(HF_Gain < 7)
				{
					HF_Gain++;
					FilManParam.DrawHF_GainBarReq = ThereIsReq;
					EqualizerChangeReq = ThereIsReq; 	// Флаг запроса изменения параметров эквалайзера
				}
				x_toch = 0;
				y_toch = 0;
			}
			else if(x_toch > 15 && x_toch < 40 && y_toch > 36 && y_toch < 54) // - Усиление высоких частот
			{
				if(HF_Gain > 0)
				{
					HF_Gain--;
					FilManParam.DrawHF_GainBarReq = ThereIsReq;
					EqualizerChangeReq = ThereIsReq; 	// Флаг запроса изменения параметров эквалайзера
				}
				x_toch = 0;
				y_toch = 0;
			}
			else if(x_toch > 200 && x_toch < 225 && y_toch > 85 && y_toch < 113) // + Граница высоких частот
			{
				if(HF_Border < 15)
				{
					HF_Border++;
					FilManParam.DrawHF_BorderBarReq = ThereIsReq;
					EqualizerChangeReq = ThereIsReq; 	// Флаг запроса изменения параметров эквалайзера
				}
				x_toch = 0;
				y_toch = 0;
			}
			else if(x_toch > 15 && x_toch < 40 && y_toch > 85 && y_toch < 113) // - Граница высоких частот
			{
				if(HF_Border > 1)
				{
					HF_Border--;
					FilManParam.DrawHF_BorderBarReq = ThereIsReq;
					EqualizerChangeReq = ThereIsReq; 	// Флаг запроса изменения параметров эквалайзера
				}
				x_toch = 0;
				y_toch = 0;
			}
			else if(x_toch > 200 && x_toch < 225 && y_toch > 138 && y_toch < 163) // + Усиление низких частот
			{
				if(LF_Gain < 15)
				{
					LF_Gain++;
					FilManParam.DrawLF_GainBarReq = ThereIsReq;
					EqualizerChangeReq = ThereIsReq; 	// Флаг запроса изменения параметров эквалайзера
				}
				x_toch = 0;
				y_toch = 0;
			}
			else if(x_toch > 15 && x_toch < 40 && y_toch > 138 && y_toch < 163) // - Усиление низких частот
			{
				if(LF_Gain > 0)
				{
					LF_Gain--;
					FilManParam.DrawLF_GainBarReq = ThereIsReq;
					EqualizerChangeReq = ThereIsReq; 	// Флаг запроса изменения параметров эквалайзера
				}
				x_toch = 0;
				y_toch = 0;
			}
			else if(x_toch > 200 && x_toch < 225 && y_toch > 195 && y_toch < 218) // + Граница низких частот
			{
				if(LF_Border < 15)
				{
					LF_Border++;
					FilManParam.DrawLF_BorderBarReq = ThereIsReq;
					EqualizerChangeReq = ThereIsReq; 	// Флаг запроса изменения параметров эквалайзера
				}
				x_toch = 0;
				y_toch = 0;
			}
			else if(x_toch > 15 && x_toch < 40 && y_toch > 195 && y_toch < 218) // - Граница низких частот
			{
				if(LF_Border > 2)
				{
					LF_Border--;
					FilManParam.DrawLF_BorderBarReq = ThereIsReq;
					EqualizerChangeReq = ThereIsReq; 	// Флаг запроса изменения параметров эквалайзера
				}
				x_toch = 0;
				y_toch = 0;
			}
		}
		
		
	  time_press = HAL_GetTick();
  }
	
	//--------------------------------------------------------------------------------------------------
	
	if(!flag_press && (HAL_GetTick() - time_press) > 250) // задержка до следующего нажатия
  {
	  flag_press = 1;
  }
	
	if(PauseReqDelay > 0) {PauseReqDelay--;}

	
		
		
    osDelay(1);
  }
  /* USER CODE END StartTask03 */
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM1 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM1) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

