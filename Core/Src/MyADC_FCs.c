#include "MyADC_FCs.h"
#include "stm32h750xx.h"
//#include "MyDefines.h"
//#include "MyCommon_FCs.h"


void ADC_Init(uint32_t* ADC_Data_, uint32_t ChanelsNumber_)
{	
	RCC->AHB4ENR |= RCC_AHB4ENR_GPIOAEN;	// Включение тактирования порта А	
	GPIOA->MODER |= GPIO_MODER_MODE0; 		// Переключение линии в аналоговый режим

	RCC->AHB1ENR |= RCC_AHB1ENR_ADC12EN;												// Включение тактирования АЦП1и2
//	
//	//ADC1->CR2 |= ADC_CR2_ADON;																// Включение АЦП1
//	ADC->CCR |= ADC_CCR_ADCPRE_1 | ADC_CCR_ADCPRE_0;					// Тактирование PCLK2 divided by 8
//	
//	//ADC1->CR2 |= ADC_CR2_CONT;																// Непрерывный режим работы АЦП
//	ADC1->SMPR2 |= ADC_SMPR2_SMP0_Msk;												// Выборка через каждые 480 cycles канал АЦП0
//	ADC1->SMPR2 |= ADC_SMPR2_SMP1_Msk;												// Выборка через каждые 480 cycles канал АЦП1
//	ADC1->SMPR2 |= ADC_SMPR2_SMP2_Msk;												// Выборка через каждые 480 cycles канал АЦП2
//	ADC1->SMPR2 |= ADC_SMPR2_SMP3_Msk;												// Выборка через каждые 480 cycles канал АЦП3
//	ADC1->SMPR2 |= ADC_SMPR2_SMP4_Msk;												// Выборка через каждые 480 cycles канал АЦП4
//	ADC1->SMPR2 |= ADC_SMPR2_SMP5_Msk;												// Выборка через каждые 480 cycles канал АЦП5
//	ADC1->SMPR2 |= ADC_SMPR2_SMP6_Msk;												// Выборка через каждые 480 cycles канал АЦП6
//	ADC1->SMPR2 |= ADC_SMPR2_SMP7_Msk;												// Выборка через каждые 480 cycles канал АЦП7
//	ADC1->SMPR2 |= ADC_SMPR2_SMP8_Msk;												// Выборка через каждые 480 cycles канал АЦП8
//	ADC1->SMPR2 |= ADC_SMPR2_SMP9_Msk;												// Выборка через каждые 480 cycles канал АЦП9
//	ADC1->SMPR1 |= ADC_SMPR1_SMP10_Msk;												// Выборка через каждые 480 cycles канал АЦП10
//	ADC1->SMPR1 |= ADC_SMPR1_SMP11_Msk;												// Выборка через каждые 480 cycles канал АЦП11
//	ADC1->SMPR1 |= ADC_SMPR1_SMP12_Msk;												// Выборка через каждые 480 cycles канал АЦП12
//	ADC1->SMPR1 |= ADC_SMPR1_SMP13_Msk;												// Выборка через каждые 480 cycles канал АЦП13
//	
//	ADC1->SQR1 = (ChanelsNumber_ - 1) << ADC_SQR1_L_Pos;			// Длина регулярной последовательности преобразований (L[3:0]) = 9 ()
//	
//	//ADC1->SQR3 = 0;//&= (~ADC_SQR3_SQ1_Msk);									
//	ADC1->SQR3 = (0x00<<ADC_SQR3_SQ1_Pos)|(0x01<<ADC_SQR3_SQ2_Pos)|(0x02<<ADC_SQR3_SQ3_Pos)|(0x03<<ADC_SQR3_SQ4_Pos); // Установка выборки с каналов АЦП 1,2,3,4
//	ADC1->SQR3 |= (0x04<<ADC_SQR3_SQ5_Pos)|(0x05<<ADC_SQR3_SQ6_Pos); // Установка выборки с каналов АЦП 5,6
//	//ADC1->SQR2 = 0x00000000;
//	ADC1->SQR2 = (0x06<<ADC_SQR2_SQ7_Pos)|(0x07<<ADC_SQR2_SQ8_Pos)|(0x08<<ADC_SQR2_SQ9_Pos)|(0x09<<ADC_SQR2_SQ10_Pos);
//	ADC1->SQR2 = (0x0A<<ADC_SQR2_SQ11_Pos)|(0x0B<<ADC_SQR2_SQ12_Pos);
//	ADC1->SQR1 |= (0x0C<<ADC_SQR1_SQ13_Pos)|(0x0D<<ADC_SQR1_SQ14_Pos);
//	
//	ADC1->CR1         |=ADC_CR1_SCAN;                					// Scan mode
//	ADC1->CR2         |=ADC_CR2_DMA;                					//разрешаем рабуту DMA
//  ADC1->CR2         |=ADC_CR2_DDS;                //DMA disable selection (for single ADC mode)
//	
//	
//	RCC->AHB1ENR    |= RCC_AHB1ENR_DMA2EN;										// Включение DMA2
//	DMA2_Stream4->CR&=~ DMA_SxCR_CHSEL;            						// 000: channel 0 selected
//	DMA2_Stream4->PAR= (uint32_t)&ADC1->DR;     							//
//  DMA2_Stream4->M0AR =(uint32_t) ADC_Data_;        					// Адрес массива, куда сохранять данные
//  DMA2_Stream4->NDTR=ChanelsNumber_;                        // Длина буфера
//	DMA2_Stream4->CR|= DMA_SxCR_MINC;            							// Инкремент адреса
//	DMA2_Stream4->CR |= DMA_SxCR_MINC | DMA_SxCR_MSIZE_1 | DMA_SxCR_PSIZE_1 | DMA_SxCR_CIRC; /* Configure increment, size, interrupts and circular mode */
//	DMA2_Stream4->CR&=~ DMA_SxCR_DIR;            							// 01: peripheral-to-Memory
//  //DMA2_Stream4->CR|= DMA_SxCR_PL;                					// 11: Very high приоритет
//	//DMA2_Stream4->CR|= DMA_SxCR_TCIE;            							// Transfer complete interrupt enable
//	
//  DMA2_Stream4->CR|= DMA_SxCR_EN;                 					// Включение DMA
//	ADC1->CR2 |= ADC_CR2_ADON;																// Включение АЦП1
//  //NVIC_EnableIRQ(DMA2_Stream4_IRQn);
//  //NVIC_SetPriority(DMA2_Stream4_IRQn,5);
//	
//	//__enable_irq ();																				// Глобальное разрешение прерываний
//	//NVIC_EnableIRQ(ADC_IRQn);																// Разрешение прерываний от АЦП
//	//ADC1->CR1 = ADC_CR1_EOCIE;															// Разрешаем прерывания по окончанию преобразования
//	
//	//запускаем АЦП по программному событию
//	ADC1->CR2 |= ADC_CR2_SWSTART;	
	
}


void AdcDmaHandling(uint32_t Source[], float SourceKalman[], uint32_t ChanelsNumber_, float PiroT_[])
{
//	float TmpFloatVar;
//	for(uint32_t i = 0; i < ChanelsNumber_; i++)
//	{
//		TmpFloatVar = (float) Source[i];
//		Kalman (0.01, &SourceKalman[i], &TmpFloatVar);
//	}
//	
//	//------------------------------------------ Пирометр 1 канал ------------------------------------------------------------
//	PiroT_[0] = (SourceKalman[10] < 785)? 0 : ((SourceKalman[10] - 785)*(float)0.52434456928838951310861423220974)/*+200*/;
//	HmiCandlesParams.Candle1.T = PiroT_[0] * 10;
	
}



/**/
