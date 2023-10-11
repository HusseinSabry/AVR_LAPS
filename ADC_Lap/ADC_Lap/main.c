/*
 * ADC_Lap.c
 *
 * Created: 10/11/2023 10:29:53 AM
 * Author : 10
 */ 

#include <avr/io.h>
#include "ADC.h"
#include "lcd.h"
#include "sensors.h"

int main(void)
{
	uint16_t data;
	uint16_t volt;
	uint16_t percent;
	uint8_t arr[16] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
	uint16_t ch; //map the number of characters on lcd with adc such as volume
	
	uint8_t i; //counter
	
	
	LCD_INIT();
	ADC_Init(VREF_AVCC,ADC_SCALER_64);
	LCD_GOTO_XY(0,0);
	LCD_WRITE_STRING("adc:");
	LCD_GOTO_XY(0,7);
	
	LCD_WRITE_CHAR('%');
	
	LCD_GOTO_XY(1,0);
	
	//LCD_WRITE_STRING(arr);
	
	
	
	
    while (1) 
    {
		
		//data =ADC_Read(CH1_7); //read data from pin 7 and save it in data 
		
		
		volt = ((uint32_t) ADC_Read(CH1_7)*5000 )/1024;
		
		
		
		LCD_WRITE_COMMAND(data);
		
		percent = (data*100)/1024;
		
		ch = percent*16 /100;
		
		LCD_WRITE_CHAR(' ');
		
		LCD_GOTO_XY(1,0);
		
		
		for(i=0;i<=ch;i++)
		{
			LCD_WRITE_CHAR(arr[i]);
			
			
		}
		
		
    }
}

