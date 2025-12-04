/**
  ******************************************************************************
  * @file    MySPI.h
  * @brief   This file contains headers of my functions.
  ******************************************************************************
*/

 /* Define to prevent recursive inclusion -------------------------------------*/
 
#ifndef __MYSPI_H
#define __MYSPI_H

#include "stdint.h"

#define XCS_Set HAL_GPIO_WritePin(XCS_GPIO_Port, XCS_Pin, GPIO_PIN_SET);
#define XCS_Reset HAL_GPIO_WritePin(XCS_GPIO_Port, XCS_Pin, GPIO_PIN_RESET);
#define XCS_State HAL_GPIO_ReadPin(XCS_GPIO_Port, XCS_Pin)

#define XDCS_Set HAL_GPIO_WritePin(XDCS_GPIO_Port, XDCS_Pin, GPIO_PIN_SET);
#define XDCS_Reset HAL_GPIO_WritePin(XDCS_GPIO_Port, XDCS_Pin, GPIO_PIN_RESET);
#define XDCS_State HAL_GPIO_ReadPin(XDCS_GPIO_Port, XDCS_Pin)

typedef enum{
	SPI1_Ok,
	SPI1_Bisy,
}SPI1_TransactionState;

void SPI1_DMA_TransmitReceive(uint8_t* SPI1_TxDataP, uint8_t* SPI1_RxDataP, uint16_t DatLen);

typedef enum{
	XCS_XDCS_0,
	XCS_XDCS_1,
}WaitXCS_XDCS_Status;


void SPI1InitSimplexTransmitterV2(uint8_t Prescaler);
void SPI1_DMA_TransmitV2(uint8_t* SPI1_TxDataP, uint16_t DatLen);
void SPI1InitFullDuplexV2(uint8_t Prescaler);
void SPI1_DMA_TransmitReceiveV2(uint8_t* SPI1_TxDataP, uint8_t* SPI1_RxDataP, uint16_t DatLen);

void SPI2InitSimplexTransmitter(uint8_t Prescaler); //«десь подключен дисплей ILI9341
extern uint32_t SPI2_DataForTransfer; //  оличество байт, которое еще осталось передать
extern uint8_t *SPI2_DataPointer;
extern uint8_t SPI2_TransferInProcess; // 1 - если передача еще не закончилась
void SPI2_DMA_TransmitIT(uint8_t* SPI2_TxDataP, uint32_t DatLen);








#endif /* __MYSPI_H */
