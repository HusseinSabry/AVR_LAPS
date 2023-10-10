/*
 * unit7_lap1_atmega.c
 *
 * Created: 9/14/2023 6:06:13 AM
 * Author : 10
 */ 

#include "MemoryMap.h"
#include <util/delay.h>
#include "Utils.h"

#define F_CPU 8000000UL

static unsigned char segmentnumber [] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6f};


int main(void)
{
	
	DDRA =0xff;
	unsigned char i ,j ;
    /* Replace with your application code */
    while (1) 
    {
		for(i=0;i<10;i++)
		{
		
		for(j=0;j<10;j++)
		{
		//	PORTA = 0b1011 |(i<<4);
			_delay_ms(50);
			
		//	PORTA =0b0111|(j<<4);
			_delay_ms(50);

		}	
		}
		
    }
}

