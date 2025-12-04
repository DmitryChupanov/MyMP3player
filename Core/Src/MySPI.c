#include "MySPI.h"
//#include "stm32h750xx.h"
#include "main.h"
#include "cmsis_os.h"



/*****************************************************************************************************************************************************/
/*******************************************************************************************************************************************************************/
void SPI1InitSimplexTransmitterV2(uint8_t Prescaler) //Здесь подключен VS1053
{
																			// Конфигурирование GPIOA
	RCC->AHB4ENR |= RCC_AHB4ENR_GPIOAEN;
	GPIOA->MODER |= GPIO_MODER_MODE5_1|GPIO_MODER_MODE6_1|GPIO_MODER_MODE7_1;
	GPIOA->MODER &= ~GPIO_MODER_MODE5_0;
	GPIOA->MODER &= ~GPIO_MODER_MODE6_0;
	GPIOA->MODER &= ~GPIO_MODER_MODE7_0;
	//GPIOA->PUPDR |= GPIO_PUPDR_PUPD6_0;
	GPIOA->AFR[0] |=  (0x05<<GPIO_AFRL_AFSEL5_Pos)|(0x05<<GPIO_AFRL_AFSEL6_Pos)|(0x05<<GPIO_AFRL_AFSEL7_Pos);
																				// Конфигурирование SPI1
	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
	SPI1->CR1 &= ~SPI_CR1_SPE;						// Отключение SPI
	SPI1->CFG1 &= ~SPI_CFG1_MBR_Msk;
	SPI1->CFG1 |= (Prescaler << SPI_CFG1_MBR_Pos)|(0x07 << SPI_CFG1_DSIZE_Pos); /*	MBR[2:0]: master baud rate
																																						000: SPI master clock/2
																																						001: SPI master clock/4
																																						010: SPI master clock/8
																																						011: SPI master clock/16
																																						100: SPI master clock/32
																																						101: SPI master clock/64
																																						110: SPI master clock/128
																																						111: SPI master clock/256*/
	SPI1->CFG2 |= SPI_CFG2_SSM | SPI_CFG2_SSOM;
	SPI1->CR1 |= SPI_CR1_SSI;
	SPI1->CFG2 |= SPI_CFG2_MASTER;
	SPI1->IFCR |= SPI_IFCR_MODFC;

																						// Настройка DMA
	RCC->AHB2ENR |= RCC_AHB2ENR_SRAM1EN | RCC_AHB2ENR_SRAM2EN | RCC_AHB2ENR_SRAM3EN; //(0x7 << 29);  				// Enable the SRAM
	RCC->AHB1ENR |= RCC_AHB1ENR_DMA1EN;   // DMA1 clock enable;
	
 // Set the peripheral and memory addresses:
	DMA1_Stream0->CR &= ~DMA_SxCR_EN; 						// Отключение потока 0
	DMA1_Stream0->PAR = (uint32_t)&SPI1->TXDR;
	DMA1_Stream0->CR = 0u;
	DMA1_Stream0->CR |= (1u << DMA_SxCR_DIR_Pos); // Memory to peripheral
	DMA1_Stream0->CR |= DMA_SxCR_MINC; 						// Memory increment mode
	DMAMUX1_Channel0->CCR  = (38u << DMAMUX_CxCR_DMAREQ_ID_Pos);
	//DMA1->LIFCR |= DMA_LISR_TCIF0;

	DMA1_Stream1->CR &= ~DMA_SxCR_EN; // Отключение потока 1
	DMA1->LIFCR |= DMA_LISR_TCIF1;


	SPI1->CFG1 |= SPI_CFG1_TXDMAEN/*|SPI_CFG1_RXDMAEN*/; // Подключение DMA только на передачу
	SPI1->CFG1 &= ~SPI_CFG1_RXDMAEN;
	
	SPI1->CFG2 |= SPI_CFG2_COMM_0; //	COMM[1:0]: SPI communication mode
	SPI1->CFG2 &= ~SPI_CFG2_COMM_1;	//	00: full-duplex
																	//	01: simplex transmitter
																	//	10: simplex receiver
																	//	11: half-duplex
																	
	DMA1_Stream0 -> CR &= ~DMA_SxCR_TCIE;	// Запрет прерывания по завершению передачи данных		
	DMA1_Stream1 -> CR &= ~DMA_SxCR_TCIE;	// Запрет прерывания по завершению приема данных
	NVIC_DisableIRQ(DMA1_Stream0_IRQn); 	// Запрет прерывания от потока на передачу данных																
	NVIC_DisableIRQ(DMA1_Stream1_IRQn);		// Запрет прерывания от потока на прием данных

	SPI1->CR1 |= SPI_CR1_SPE;				// Включение SPI
}
/*****************************************************************************************************************************************************/
void SPI1_DMA_TransmitV2(uint8_t* SPI1_TxDataP, uint16_t DatLen)
{
	DMA1_Stream0->CR &= ~DMA_SxCR_EN;								// Запрет потока
	DMA1->LIFCR |= DMA_LIFCR_CFEIF0|DMA_LIFCR_CDMEIF0|DMA_LIFCR_CTEIF0|DMA_LIFCR_CHTIF0|DMA_LIFCR_CTCIF0; // Сброс всех флагов
	DMA1_Stream0->M0AR = (uint32_t)SPI1_TxDataP;		// Указатель на буфер где брать данные
	DMA1_Stream0->NDTR = DatLen; 										// Number of data
	DMA1->LIFCR |= DMA_LISR_TCIF0;									// Сброс флага прерывания по завершению передачи
	//DMA1_Stream0 -> CR |= DMA_SxCR_TCIE;						// Разрешение прерывания по завершению передачи данных
	
	SPI1->IFCR |= SPI_IFCR_TXTFC;
	SPI1->IFCR |= SPI_IFCR_EOTC;
	SPI1->CR1 |= SPI_CR1_CSTART;

	DMA1_Stream0->CR |= DMA_SxCR_EN;
	
	__NOP(); __NOP(); __NOP(); __NOP();

}
/*****************************************************************************************************************************************************/
// Предделитель частоты
/*MBR[2:0]: master baud rate
	000: SPI master clock/2
	001: SPI master clock/4
	010: SPI master clock/8
	011: SPI master clock/16
	100: SPI master clock/32
	101: SPI master clock/64
	110: SPI master clock/128
	111: SPI master clock/256
*/
void SPI1InitFullDuplexV2(uint8_t Prescaler)
{
																				// Конфигурирование GPIOA
	RCC->AHB4ENR |= RCC_AHB4ENR_GPIOAEN;
	GPIOA->MODER |= GPIO_MODER_MODE5_1|GPIO_MODER_MODE6_1|GPIO_MODER_MODE7_1;
	GPIOA->MODER &= ~GPIO_MODER_MODE5_0;
	GPIOA->MODER &= ~GPIO_MODER_MODE6_0; 
	GPIOA->MODER &= ~GPIO_MODER_MODE7_0;
	//GPIOA->PUPDR |= GPIO_PUPDR_PUPD6_0; // MISO
	GPIOA->AFR[0] |=  (0x05<<GPIO_AFRL_AFSEL5_Pos)|(0x05<<GPIO_AFRL_AFSEL6_Pos)|(0x05<<GPIO_AFRL_AFSEL7_Pos);
																				// Конфигурирование SPI1
	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
	SPI1->CR1 &= ~SPI_CR1_SPE;						// Отключение SPI
	SPI1->CFG1 |= (Prescaler << SPI_CFG1_MBR_Pos)|(0x07 << SPI_CFG1_DSIZE_Pos); /*	MBR[2:0]: master baud rate
																																						000: SPI master clock/2
																																						001: SPI master clock/4
																																						010: SPI master clock/8
																																						011: SPI master clock/16
																																						100: SPI master clock/32
																																						101: SPI master clock/64
																																						110: SPI master clock/128
																																						111: SPI master clock/256*/
	SPI1->CFG2 |= SPI_CFG2_SSM | SPI_CFG2_SSOM;
	SPI1->CR1 |= SPI_CR1_SSI;
	SPI1->CFG2 |= SPI_CFG2_MASTER;
	SPI1->IFCR |= SPI_IFCR_MODFC;

																						// Настройка DMA
	RCC->AHB2ENR |= RCC_AHB2ENR_SRAM1EN | RCC_AHB2ENR_SRAM2EN | RCC_AHB2ENR_SRAM3EN; //(0x7 << 29);  				// Enable the SRAM
	RCC->AHB1ENR |= RCC_AHB1ENR_DMA1EN;   // DMA1 clock enable;
	
 // Set the peripheral and memory addresses:
	DMA1_Stream0->CR &= ~DMA_SxCR_EN; // Отключение потока 0
	DMA1_Stream0->PAR = (uint32_t)&SPI1->TXDR;
	DMA1_Stream0->CR = 0u;
	DMA1_Stream0->CR |= (1u << DMA_SxCR_DIR_Pos); // Memory to peripheral
	DMA1_Stream0->CR |= DMA_SxCR_MINC; 						// Memory increment mode
	DMAMUX1_Channel0->CCR  = (38u << DMAMUX_CxCR_DMAREQ_ID_Pos);
	DMA1->LIFCR |= DMA_LISR_TCIF0;

	DMA1_Stream1->CR &= ~DMA_SxCR_EN; // Отключение потока 1
	DMA1_Stream1->PAR = (uint32_t)&SPI1->RXDR;
	DMA1_Stream1->CR = 0u;
	DMA1_Stream1->CR &= ~DMA_SxCR_DIR_Msk; 		// Peripheral-to-memory
	DMA1_Stream1->CR |= DMA_SxCR_MINC; 				// Memory increment mode
	DMAMUX1_Channel1->CCR  = (37u << DMAMUX_CxCR_DMAREQ_ID_Pos);
	DMA1->LIFCR |= DMA_LISR_TCIF1;


	SPI1->CFG1 |= SPI_CFG1_TXDMAEN|SPI_CFG1_RXDMAEN; // Подключение DMA на передачу и прием
	
	SPI1->CFG2 &= ~SPI_CFG2_COMM_0; //	COMM[1:0]: SPI communication mode
	SPI1->CFG2 &= ~SPI_CFG2_COMM_1;	//	00: full-duplex
																	//	01: simplex transmitter
																	//	10: simplex receiver
																	//	11: half-duplex
	DMA1_Stream0 -> CR &= ~DMA_SxCR_TCIE;	// Запрет прерывания по завершению передачи данных		
	DMA1_Stream1 -> CR &= ~DMA_SxCR_TCIE;	// Запрет прерывания по завершению приема данных
	NVIC_DisableIRQ(DMA1_Stream0_IRQn); 	// Запрет прерывания от потока на передачу данных																
	NVIC_DisableIRQ(DMA1_Stream1_IRQn); 		// Разрешение прерывания от потока на прием данных

	SPI1->CR1 |= SPI_CR1_SPE;				// Включение SPI
}
/*******************************************************************************************************************************************************************/
void SPI1_DMA_TransmitReceiveV2(uint8_t* SPI1_TxDataP, uint8_t* SPI1_RxDataP, uint16_t DatLen)
{
	DMA1_Stream0->CR &= ~DMA_SxCR_EN;
	DMA1->LIFCR |= DMA_LIFCR_CFEIF0|DMA_LIFCR_CDMEIF0|DMA_LIFCR_CTEIF0|DMA_LIFCR_CHTIF0|DMA_LIFCR_CTCIF0; // Сброс всех флагов
	DMA1_Stream0->M0AR = (uint32_t)SPI1_TxDataP;		// Указатель на буфер где брать данные
	DMA1_Stream0->NDTR = DatLen; 										// Number of data
	
	DMA1_Stream1->CR &= ~DMA_SxCR_EN;
	DMA1->LIFCR |= DMA_LIFCR_CFEIF1|DMA_LIFCR_CDMEIF1|DMA_LIFCR_CTEIF1|DMA_LIFCR_CHTIF1|DMA_LIFCR_CTCIF1; // Сброс всех флагов
	DMA1_Stream1->M0AR = (uint32_t)SPI1_RxDataP;		// Указатель на буфер куда ложить данные
	DMA1_Stream1->NDTR = DatLen; 										// Number of data
			
	SPI1->IFCR |= SPI_IFCR_TXTFC;
	SPI1->IFCR |= SPI_IFCR_EOTC;
	SPI1->CR1 |= SPI_CR1_CSTART;

	DMA1_Stream1->CR |= DMA_SxCR_EN;
	DMA1_Stream0->CR |= DMA_SxCR_EN;
	
	__NOP(); __NOP(); __NOP(); __NOP();
}
/*******************************************************************************************************************************************************************/
//000: SPI master clock/2
//001: SPI master clock/4
//010: SPI master clock/8
//011: SPI master clock/16
//100: SPI master clock/32
//101: SPI master clock/64
//110: SPI master clock/128
//111: SPI master clock/256
void SPI2InitSimplexTransmitter(uint8_t Prescaler) //Здесь подключен дисплей ILI9341
{
																			// Конфигурирование GPIOC и GPIOB
	RCC->AHB4ENR |= RCC_AHB4ENR_GPIOCEN;
	GPIOC->MODER |= GPIO_MODER_MODE1_1|GPIO_MODER_MODE2_1;
	GPIOC->MODER &= ~GPIO_MODER_MODE1_0;
	GPIOC->MODER &= ~GPIO_MODER_MODE2_0;
	GPIOC->OSPEEDR |= GPIO_OSPEEDR_OSPEED1_0|GPIO_OSPEEDR_OSPEED1_1|GPIO_OSPEEDR_OSPEED2_0|GPIO_OSPEEDR_OSPEED2_1; // Скорость пинов максимальная
	RCC->AHB4ENR |= RCC_AHB4ENR_GPIOBEN;
	GPIOB->MODER |= GPIO_MODER_MODE10_1;
	GPIOB->MODER &= ~GPIO_MODER_MODE10_0;
	GPIOB->OSPEEDR |= GPIO_OSPEEDR_OSPEED10_0|GPIO_OSPEEDR_OSPEED10_1; // Скорость пина максимальная
	GPIOC->AFR[0] |=  (0x05<<GPIO_AFRL_AFSEL1_Pos)|(0x05<<GPIO_AFRL_AFSEL2_Pos);
	GPIOB->AFR[1] |=  (0x05<<GPIO_AFRH_AFSEL10_Pos);
	
																				// Конфигурирование SPI2
	RCC->APB1LENR |= RCC_APB1LENR_SPI2EN;
	SPI2->CR1 &= ~SPI_CR1_SPE;						// Отключение SPI
	SPI2->CFG1 &= ~SPI_CFG1_MBR_Msk;
	SPI2->CFG1 |= (Prescaler << SPI_CFG1_MBR_Pos)|(0x07 << SPI_CFG1_DSIZE_Pos); /*	MBR[2:0]: master baud rate
																																						000: SPI master clock/2
																																						001: SPI master clock/4
																																						010: SPI master clock/8
																																						011: SPI master clock/16
																																						100: SPI master clock/32
																																						101: SPI master clock/64
																																						110: SPI master clock/128
																																						111: SPI master clock/256*/
	SPI2->CFG2 |= SPI_CFG2_SSM | SPI_CFG2_SSOM;
	SPI2->CR1 |= SPI_CR1_SSI;
	SPI2->CFG2 |= SPI_CFG2_MASTER;
	SPI2->IFCR |= SPI_IFCR_MODFC;

																						// Настройка DMA
	RCC->AHB2ENR |= RCC_AHB2ENR_SRAM1EN | RCC_AHB2ENR_SRAM2EN | RCC_AHB2ENR_SRAM3EN; //(0x7 << 29);  				// Enable the SRAM
	RCC->AHB1ENR |= RCC_AHB1ENR_DMA1EN;   // DMA1 clock enable;
	
 // Set the peripheral and memory addresses:
	DMA1_Stream2->CR &= ~DMA_SxCR_EN; 						// Отключение потока 2 TX
	DMA1_Stream2->PAR = (uint32_t)&SPI2->TXDR;
	DMA1_Stream2->CR = 0u;
	DMA1_Stream2->CR |= (1u << DMA_SxCR_DIR_Pos); // Memory to peripheral
	DMA1_Stream2->CR |= DMA_SxCR_MINC; 						// Memory increment mode
	DMAMUX1_Channel2->CCR  = (40u << DMAMUX_CxCR_DMAREQ_ID_Pos);
	//DMA1->LIFCR |= DMA_LISR_TCIF0;

	//DMA1_Stream3->CR &= ~DMA_SxCR_EN; // Отключение потока 1
	//DMA1->LIFCR |= DMA_LISR_TCIF3;


	SPI2->CFG1 |= SPI_CFG1_TXDMAEN/*|SPI_CFG1_RXDMAEN*/; // Подключение DMA только на передачу
	SPI2->CFG1 &= ~SPI_CFG1_RXDMAEN;
	
	SPI2->CFG2 |= SPI_CFG2_COMM_0; //	COMM[1:0]: SPI communication mode
	SPI2->CFG2 &= ~SPI_CFG2_COMM_1;	//	00: full-duplex
																	//	01: simplex transmitter
																	//	10: simplex receiver
																	//	11: half-duplex
																	
	DMA1_Stream2 -> CR &= ~DMA_SxCR_TCIE;	// Запрет прерывания по завершению передачи данных		
	//DMA1_Stream3 -> CR &= ~DMA_SxCR_TCIE;	// Запрет прерывания по завершению приема данных
	NVIC_EnableIRQ(DMA1_Stream2_IRQn); 	// Разрешение прерывания от потока на передачу данных																
	//NVIC_DisableIRQ(DMA1_Stream2_IRQn);		// Запрет прерывания от потока на прием данных

	SPI2->CR1 |= SPI_CR1_SPE;				// Включение SPI
}
/*************************************************************** Передача в дисплей *****************************************************************/
//void SPI2_DMA_Transmit(uint8_t* SPI2_TxDataP, uint16_t DatLen)
//{
//	DMA1_Stream2->CR &= ~DMA_SxCR_EN;								// Запрет потока
//	DMA1->LIFCR |= DMA_LIFCR_CFEIF2|DMA_LIFCR_CDMEIF2|DMA_LIFCR_CTEIF2|DMA_LIFCR_CHTIF2|DMA_LIFCR_CTCIF2; // Сброс всех флагов
//	DMA1_Stream2->M0AR = (uint32_t)SPI2_TxDataP;		// Указатель на буфер где брать данные
//	DMA1_Stream2->NDTR = DatLen; 										// Number of data
//	DMA1->LIFCR |= DMA_LISR_TCIF2;									// Сброс флага прерывания по завершению передачи
//	//DMA1_Stream2 -> CR |= DMA_SxCR_TCIE;						// Разрешение прерывания по завершению передачи данных
//	
//	SPI2->IFCR |= SPI_IFCR_TXTFC;
//	SPI2->IFCR |= SPI_IFCR_EOTC;
//	SPI2->CR1 |= SPI_CR1_CSTART;

//	DMA1_Stream2->CR |= DMA_SxCR_EN;
//	__NOP(); __NOP(); __NOP(); __NOP();

//}
/*****************************************************************************************************************************************************/
/*************************************************************** Передача в дисплей *****************************************************************/
uint32_t SPI2_DataForTransfer; // Количество байт, которое еще осталось передать
uint8_t *SPI2_DataPointer;
uint8_t SPI2_TransferInProcess = 0; // 1 - если передача еще не закончилась
void SPI2_DMA_TransmitIT(uint8_t* SPI2_TxDataP, uint32_t DatLen)
{
	SPI2_DataForTransfer = DatLen;
	DMA1_Stream2->CR &= ~DMA_SxCR_EN;								// Запрет потока
	DMA1->LIFCR |= DMA_LIFCR_CFEIF2|DMA_LIFCR_CDMEIF2|DMA_LIFCR_CTEIF2|DMA_LIFCR_CHTIF2|DMA_LIFCR_CTCIF2; // Сброс всех флагов
	DMA1_Stream2->M0AR = (uint32_t)SPI2_TxDataP;		// Указатель на буфер где брать данные
	if(DatLen > 65535)
	{
		DMA1_Stream2->NDTR = 65535; 										// Number of data
		SPI2_DataForTransfer -= 65535;									// Количество данных, которые нужно будет передать при последующих циклах DMA
		SPI2_TransferInProcess = 1;											// Флаг: "Передача в процессе"
		SPI2_DataPointer = SPI2_TxDataP + 65535;
	}
	else
	{
		DMA1_Stream2->NDTR = DatLen; 										// Number of data
		SPI2_DataForTransfer = 0;												// Количество данных, которые нужно будет передать при последующих циклах DMA
		SPI2_TransferInProcess = 1;											// Флаг: "Передача в процессе"
	}
	
	DMA1->LIFCR |= DMA_LIFCR_CTCIF2;									// Сброс флага прерывания по завершению передачи
	DMA1_Stream2 -> CR |= DMA_SxCR_TCIE;						// Разрешение прерывания по завершению передачи данных
	
	SPI2->IFCR |= SPI_IFCR_TXTFC;
	SPI2->IFCR |= SPI_IFCR_EOTC;
	SPI2->CR1 |= SPI_CR1_CSTART;

	DMA1_Stream2->CR |= DMA_SxCR_EN;
	__NOP(); __NOP(); __NOP(); __NOP();

}
/*****************************************************************************************************************************************************/


















/**/
