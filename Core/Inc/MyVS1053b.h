/**
  ******************************************************************************
  * @file    MyVS1053b.h
  * @brief   This file contains headers of my functions.
  ******************************************************************************
*/

 /* Define to prevent recursive inclusion -------------------------------------*/
 
#ifndef __MYVS1053B_H
#define __MYVS1053B_H

#include "stdint.h"
//#include "main.h"
//#include "cmsis_os.h"

#define vs_MODE 0x00
	#define SM_DIFF 0x0001
	#define SM_LAYER12 0x0002
	#define SM_RESET 0x0004
	#define SM_CANCEL 0x0008
	#define SM_EARSPEAKER_LO 0x0010
	#define SM_TESTS 0x0020
	#define SM_STREAM 0x0040
	#define SM_EARSPEAKER_HI 0x0080
	#define	SM_DACT 0x0100
	#define SM_SDIORD 0x0200
	#define SM_SDISHARE 0x0400
	#define SM_SDINEW 0x0800
	#define SM_ADPCM 0x1000
	#define SM_LINE1 0x4000
	#define SM_CLK_RANGE 0x8000

#define vs_STATUS 0x01
	#define SS_REFERENCE_SEL 0x01
	#define SS_AD_CLOCK 0x02
	#define SS_APDOWN1 0x04
	#define SS_APDOWN2 0x08
	#define SS_VER 0x40				// Версия всегда 4 для VS1053b
	#define SS_VCM_DISABLE 0x04
	#define SS_VCM_OVERLOAD 0x08
	#define SS_SWING_0 0x10
	#define SS_SWING_1 0x20
	#define SS_SWING_2 0x40
	#define SS_DO_NOT_JUMP 0x80

#define vs_BASS 0x02
	#define TREBLE_AMPLITUDE_pos 12
	#define TREBLE_FREQLIMIT_pos 8
	#define	BASS_AMPLITUDE_pos 4
	#define	BASS_FREQLIMIT_pos 0

#define vs_CLOCKF 0x03
#define vs_DECODE_TIME 0x04
#define vs_AUDATA 0x05
#define vs_WRAM 0x06
#define vs_WRAMADDR 0x07
#define vs_HDAT0 0x08
#define vs_HDAT1 0x09
#define vs_AIADDR 0x0A
#define vs_VOL 0x0B
#define vs_AICTRL0 0x0C
#define vs_AICTRL1 0x0D
#define vs_AICTRL2 0x0E
#define vs_AICTRL3 0x0F

#define vs_READ 0x03
#define vs_WRITE 0x02

#define DREQ_State HAL_GPIO_ReadPin(DREQ_GPIO_Port, DREQ_Pin)

typedef enum{
	DREQ_0,
	DREQ_1,
}WaitDREQ_Status;


WaitDREQ_Status WaitDREQ(void);

void SineTest(uint8_t Volume);
void VolumeChange(uint8_t Volume);

typedef enum{
	SCI_Ok,
	SCI_Error,
}SCI_StatusTypedef;

SCI_StatusTypedef WriteSCI_Reg(uint8_t RegAddr, uint8_t ValueH, uint8_t ValueL);
SCI_StatusTypedef ReadSCI_Reg(uint8_t RegAddr, uint16_t* RegContent);

//#define VS1053_RESET_RES() HAL_GPIO_WritePin(GPIOE,XRST_Pin, GPIO_PIN_RESET);
//#define VS1053_SET_RES() HAL_GPIO_WritePin(GPIOE,XRST_Pin, GPIO_PIN_SET);
#define VS1053_SET_XCS() HAL_GPIO_WritePin(XCS_GPIO_Port, XCS_Pin, GPIO_PIN_SET);
#define VS1053_RESET_XCS() HAL_GPIO_WritePin(XCS_GPIO_Port, XCS_Pin, GPIO_PIN_RESET);
#define VS1053_SET_XDCS() HAL_GPIO_WritePin(XDCS_GPIO_Port, XDCS_Pin, GPIO_PIN_SET);
#define VS1053_RESET_XDCS() HAL_GPIO_WritePin(XDCS_GPIO_Port, XDCS_Pin, GPIO_PIN_RESET);
#define VS1053_DREQ HAL_GPIO_ReadPin(DREQ_GPIO_Port, DREQ_Pin)
#define VS1053_CMD_READ 0x03 // Read Opcode
#define VS1053_CMD_WRITE 0x02 // Write Opcode
#define vs1053_MODE 0x00 // Mode control
#define vs1053_STATUS 0x01 // Status of vs1053b
#define vs1053_CLOCKF 0x03 // Clock freq + doubler
#define vs1053_AUDATA 0x05 // Misc. audio data
#define vs1053_VOL 0x0B // Volume control
#define SM_SDINEW 0x0800 // VS1002 native SPI modes 11 bit
#define SM_RESET 0x0004 // Soft Reset
#define SM_TESTS 0x0020 // Allow SDI tests


void WriteSCI_RegV2(uint8_t RegAddr, uint8_t ValueH, uint8_t ValueL);
void WriteSCI_Reg16(uint8_t RegAddr, uint16_t Value);
void ReadSCI_RegV2(uint8_t RegAddr, uint16_t* RegContent);
void HardReset(uint8_t Vol_,uint8_t HF_Gain_, uint8_t HF_Border_, uint8_t LF_Gain_,uint8_t LF_Border_);
void SoftReset(void);
















#endif /* __MYVS1053B_H */
