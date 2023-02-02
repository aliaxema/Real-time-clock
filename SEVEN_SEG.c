/*
 * SEVEN_SEG.c
 *
 * Created: 8/13/2022 12:52:50 PM
 *  Author: safifi
 */ 
#include "SEVEN_SEG.h"

uint8_t num[10]={0b0111111,0b0000110,0b1011011,0b1001111,0b1100110,0b1101101,0b1111101,0b00000111,0b01111111,0b01101111};

void SEVEN_SEG_init(void){
	INIT_SEVEN_SEG_PINS;
}

void SEVEN_SEG_write(uint8_t data , uint8_t num_ss){ 
	Disable_All_SS;
	PORT_WRITE_PORTC=num[data];
	switch(num_ss)
	{
		case 1: {
		EN1; 
	//	uint8_t x = data / 10;
		
	//	PORT_WRITE_PORTC=num[x];
		//_delay_ms(10);
		break;
		}
		case 2: {
			EN2; 
		//	uint8_t x = data % 10;
			
		//	PORT_WRITE_PORTC=num[x];
		//	_delay_ms(10);
			break;}
		case 3: {
		EN3;
	//	uint8_t x = data / 10;
		
		//PORT_WRITE_PORTC=num[x];
		//_delay_ms(10);
		break;
		}
		case 4: {
		EN4;
		//uint8_t x = data % 10;
		
		//PORT_WRITE_PORTC=num[x];
		//_delay_ms(10);
		break;
		}
		
		case 5:{ 
		EN5;
		//uint8_t x = data / 10;
		//PORT_WRITE_PORTC=num[x];
		//_delay_ms(10);
		break;
		}
		case 6:{
		 EN6; 
		//uint8_t x = data % 10;
		
		//_delay_ms(10);
		break;
		}
		
		
	}
	
	
	
	
}
