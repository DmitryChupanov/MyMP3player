/**
  ******************************************************************************
  * @file    MyADC_FCs.h
  * @brief   This file contains headers of my functions.
  ******************************************************************************
*/

 /* Define to prevent recursive inclusion -------------------------------------*/
 
#ifndef __MYADC_FCS_H
#define __MYADC_FCS_H

#include "stdint.h"

void ADC_Init(uint32_t* ADC_Data_, uint32_t ChanelsNumber_);
void AdcDmaHandling(uint32_t Source[], float SourceKalman[], uint32_t ChanelsNumber_, float PiroT_[]);

#endif /* __MYADC_FCS_H */
