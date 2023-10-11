/*
 * ADC.h
 *
 * Created: 10/11/2023 10:45:41 AM
 *  Author: 10
 */ 


#ifndef ADC_H_
#define ADC_H_


#include "Utils.h"
#include "stdTypes.h"
#include "MemMap.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define SET_BIT(ADDRESS,BIT) ADDRESS |= (1<<BIT)
#define RESET_BIT(ADDRESS,BIT) ADDRESS &= ~(1<<BIT)
#define TOGGLE_BIT(ADDRESS,BIT) ADDRESS ^= (1<<BIT)
#define READ_BIT(ADDRESS,BIT) ((ADDRESS & (1<<BIT))>>BIT)





#define VoltRef 5000

#define Res 1024

typedef enum
{
	VREF_AREF,
	VREF_AVCC,
	VREF_256
	
}ADC_Vref_Type;

typedef enum
{
	ADC_SCALER_2=0,
	ADC_SCALER_4=2,
	ADC_SCALER_8,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64,
	ADC_SCALER_128
	
}ADC_Scaler_Type;

typedef enum 
{
	CH_0=0, 
	CH1_1,
	CH1_2,
	CH1_3,
	CH1_4,
	CH1_5,
	CH1_6,
	CH1_7
	
}ADC_Channel_Type; //ADC from pin 0 to pin 7



void ADC_Init(ADC_Vref_Type vref , ADC_Scaler_Type Scaler);

uint16_t ADC_Read (ADC_Channel_Type ch);









#endif /* ADC_H_ */