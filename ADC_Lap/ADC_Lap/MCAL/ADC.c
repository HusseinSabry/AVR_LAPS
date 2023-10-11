/*
 * ADC.c
 *
 * Created: 10/11/2023 10:46:05 AM
 *  Author: Hussein Sabry
 
 */ 
#include "ADC.h"

void ADC_Init(ADC_Vref_Type vref , ADC_Scaler_Type Scaler)
{
	
	//check vref
	
	switch (vref)
	{
		case VREF_AREF:
		RESET_BIT (ADMUX,REFS0);
		RESET_BIT (ADMUX,REFS1);
		break;
		
		case VREF_AVCC:
		SET_BIT   (ADMUX,REFS0);
		RESET_BIT (ADMUX,REFS1);
		break;
		
		case VREF_256:
		SET_BIT (ADMUX,REFS0);
		SET_BIT (ADMUX,REFS1);
		break;
		
	}
	
	//prescaler
	ADCSRA &= 0xf8;
	ADCSRA |= Scaler;
	SET_BIT (ADCSRA ,ADEN);
	
	
	
	
	
}

uint16_t ADC_Read (ADC_Channel_Type ch)
{
	
	//select channel
	ADMUX &=0xE0;
	ADMUX |=ch;
	
	//Start conversion
	
	SET_BIT(ADCSRA,ADSC);
	
	while (READ_BIT(ADCSRA,ADSC));
	return ADC;
	
	
	
}

