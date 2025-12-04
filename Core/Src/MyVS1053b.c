#include "MyVS1053b.h"
#include "main.h"
#include "cmsis_os.h"
#include "MySPI.h"

WaitDREQ_Status WaitDREQ(void)
{
	for(uint8_t i = 0; i < 200; i++)
	{
		if(DREQ_State == GPIO_PIN_SET)
		{
			return DREQ_1;
		}
		osDelay(1);
	}
	return DREQ_0;
}

void SineTest(uint8_t Volume)
{
	uint8_t TX_DATA[8];
	HAL_GPIO_WritePin(XRESET_GPIO_Port, XRESET_Pin, GPIO_PIN_RESET);
	osDelay(10);
	HAL_GPIO_WritePin(XRESET_GPIO_Port, XRESET_Pin, GPIO_PIN_SET);
	osDelay(10);
	while(!VS1053_DREQ){__NOP();};
	WriteSCI_RegV2(vs_VOL, Volume, Volume);
	osDelay(1);
	WriteSCI_Reg16(vs_MODE, (SM_LINE1|SM_SDINEW|SM_TESTS));
	while(!VS1053_DREQ){__NOP();};
	TX_DATA[0] = 0x53;
	TX_DATA[1] = 0xEF;
	TX_DATA[2] = 0x6E;
	TX_DATA[3] = 126;
	TX_DATA[4] = 0x00;
	TX_DATA[5] = 0x00;
	TX_DATA[6] = 0x00;
	TX_DATA[7] = 0x00;
	XCS_Set
	XDCS_Reset
	SPI1_DMA_TransmitV2(TX_DATA, 8);
	while( ((SPI1->SR & SPI_SR_TXC)==0)||((SPI1->SR & SPI_SR_TXP)==0)||((DMA1->LISR & DMA_LISR_TCIF0)==0)||((DMA1->LISR & DMA_LISR_FEIF0)==0) )
	{
		__NOP();
	}
	__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
	while(!VS1053_DREQ){__NOP();};
	__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
	XDCS_Set
	__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
	

}
/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/
void WriteSCI_RegV2(uint8_t RegAddr, uint8_t ValueH, uint8_t ValueL)
{
	uint8_t TX_DATA[4];
	if(((SPI1->CFG2 & SPI_CFG2_COMM_Msk)>>SPI_CFG2_COMM_Pos) != 0x01 || ((SPI1->CFG1 & SPI_CFG1_MBR_Msk)>>SPI_CFG1_MBR_Pos)!=0x06) 				// ≈сли трансмитер находитс€ не в режиме 01: simplex transmitter
	{
		VS1053_SET_XDCS();
		VS1053_SET_XCS();
		SPI1InitSimplexTransmitterV2(0x06);		// “о перевести его в этот режим	
	}
	TX_DATA[0] = vs_WRITE;	// команда записи
	TX_DATA[1] = RegAddr;
	TX_DATA[2] = ValueH;
	TX_DATA[3] = ValueL;
	VS1053_SET_XDCS();
	VS1053_RESET_XCS();
	SPI1_DMA_TransmitV2(TX_DATA, 4);
	while( ((SPI1->SR & SPI_SR_TXC)==0)||((SPI1->SR & SPI_SR_TXP)==0)||((DMA1->LISR & DMA_LISR_TCIF0)==0)||((DMA1->LISR & DMA_LISR_FEIF0)==0) )
	{
		__NOP();
	}
	__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
	while(!VS1053_DREQ){__NOP();};
	__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
	VS1053_SET_XCS();
	__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
}
/*****************************************************************************************************************************************************/
void WriteSCI_Reg16(uint8_t RegAddr, uint16_t Value)
{
	uint8_t TX_DATA[4];
	if((((SPI1->CFG2 & SPI_CFG2_COMM_Msk)>>SPI_CFG2_COMM_Pos) != 0x01)||(((SPI1->CFG1 & SPI_CFG1_MBR_Msk)>>SPI_CFG1_MBR_Pos)!=0x06)) // ≈сли трансмитер находитс€ не в режиме 01: simplex transmitter
																																																														// или не тот делитель
	{
		VS1053_SET_XDCS();
		VS1053_SET_XCS();
		SPI1InitSimplexTransmitterV2(0x06);		// “о перевести его в этот режим	
	}
	TX_DATA[0] = vs_WRITE;	// команда записи
	TX_DATA[1] = RegAddr;
	TX_DATA[2] = (Value>>8);
	TX_DATA[3] = Value;
	VS1053_SET_XDCS();
	VS1053_RESET_XCS();
	SPI1_DMA_TransmitV2(TX_DATA, 4);
	while( ((SPI1->SR & SPI_SR_TXC)==0)||((SPI1->SR & SPI_SR_TXP)==0)||((DMA1->LISR & DMA_LISR_TCIF0)==0)||((DMA1->LISR & DMA_LISR_FEIF0)==0) )
	{
		__NOP();
	}
	__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
	while(!VS1053_DREQ){__NOP();};
	__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
	VS1053_SET_XCS();
	__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
}
/*****************************************************************************************************************************************************/
void ReadSCI_RegV2(uint8_t RegAddr, uint16_t* RegContent)
{
	uint8_t RX_DATA[4]={0,0,0,0};
	uint8_t TX_DATA[4];
	uint16_t TmpVal = 0;
	TX_DATA[0] = vs_READ;	
	TX_DATA[1] = RegAddr;
	TX_DATA[2] = 0;
	TX_DATA[3] = 0;
	if(((SPI1->CFG2 & SPI_CFG2_COMM_Msk) != 0)||((SPI1->CR1 & SPI_CR1_SPE) == 0))				// ≈сли трансмитер находитс€ не в режиме 00: full-duplex
	{
		VS1053_SET_XDCS();
		VS1053_SET_XCS();
		SPI1InitFullDuplexV2(0x06);															// “о перевести его в этот режим	
	}
	VS1053_SET_XDCS();
	VS1053_RESET_XCS();
	SPI1_DMA_TransmitReceiveV2(TX_DATA, RX_DATA, 4);
	while( ((SPI1->SR & SPI_SR_TXC)==0)||((SPI1->SR & SPI_SR_TXP)==0)||((DMA1->LISR & DMA_LISR_TCIF0)==0)||((DMA1->LISR & DMA_LISR_FEIF0)==0) )
	{
		__NOP();
	}
	while( ((SPI1->SR & SPI_SR_TXC)==0)||((SPI1->SR & SPI_SR_RXP)==1)||((DMA1->LISR & DMA_LISR_TCIF1)==0) )
	{
		__NOP();
	}
	while(!VS1053_DREQ){__NOP();};
	TmpVal = RX_DATA[2];
	TmpVal = TmpVal << 8;
	TmpVal |= RX_DATA[3];
	*RegContent = TmpVal;
	VS1053_SET_XCS();
}

/*****************************************************************************************************************************************************/
void HardReset(uint8_t Vol_,uint8_t HF_Gain_, uint8_t HF_Border_, uint8_t LF_Gain_,uint8_t LF_Border_)
{
	XCS_Set
	XDCS_Set
	HAL_GPIO_WritePin(XRESET_GPIO_Port, XRESET_Pin, GPIO_PIN_RESET);
	osDelay(5);
	HAL_GPIO_WritePin(XRESET_GPIO_Port, XRESET_Pin, GPIO_PIN_SET);
	osDelay(2);
	while(!VS1053_DREQ){__NOP();};
	WriteSCI_Reg16(vs_CLOCKF, 0xF800);
	osDelay(10);
	WriteSCI_Reg16(vs_MODE, (SM_LINE1|SM_SDINEW|SM_EARSPEAKER_LO|SM_LAYER12));
	osDelay(1);
	WriteSCI_Reg16(vs_BASS, (HF_Gain_<<TREBLE_AMPLITUDE_pos | HF_Border_<<TREBLE_FREQLIMIT_pos|LF_Gain_<<BASS_AMPLITUDE_pos | LF_Border_)/*0x7A18*/);
	osDelay(1);
	WriteSCI_RegV2(vs_VOL, Vol_, Vol_);
	osDelay(1);
}
/*****************************************************************************************************************************************************/
void SoftReset(void)
{
	WriteSCI_Reg16(vs_MODE, (SM_LINE1|SM_SDINEW|SM_RESET));
	osDelay(2);
	while(!VS1053_DREQ){__NOP();};
}
/*****************************************************************************************************************************************************/

/*****************************************************************************************************************************************************/

/*****************************************************************************************************************************************************/

/*****************************************************************************************************************************************************/

/*****************************************************************************************************************************************************/

/*****************************************************************************************************************************************************/


/**/
