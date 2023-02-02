/*
 * LCD_Q1.h
 *
 * Created: 17-Aug-22 2:57:44 PM
 *  Author: lenovo
 */ 


#ifndef LCD_Q1_H_
#define LCD_Q1_H_

#include "std_macros.h"

#define LCD_init_Pins DDRA|=0b11111100; //PD2 to PD7 are output as there are D4-D7 in LCD , the EN and RS

#define EN(x) if(x==1) SETBIT(PORTA,2); else CLRBIT(PORTA,2);
#define RS(x) if(x==1) SETBIT(PORTA,3); else CLRBIT(PORTA,3);
#define D7(x) if(x==1) SETBIT(PORTA,7); else CLRBIT(PORTA,7);
#define D6(x) if(x==1) SETBIT(PORTA,6); else CLRBIT(PORTA,6);
#define D5(x) if(x==1) SETBIT(PORTA,5); else CLRBIT(PORTA,5);
#define D4(x) if(x==1) SETBIT(PORTA,4); else CLRBIT(PORTA,4);


//configure LCD port
void LCD_init(void);

//send command to LCD
void LCD_write_command(uint8_t data);

//send data to CD
void LCD_write_char(uint8_t data);

//write a sentence
void LCD_write_string(uint8_t *data);

//write a number
void LCD_write_num(uint16_t data);




#endif /* LCD_Q1_H_ */