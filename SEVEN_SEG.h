/*
 * SEVEN_SEG.h
 *
 * Created: 8/13/2022 12:53:05 PM
 *  Author: safifi
 */ 


#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_

#include "std_macros.h"

#define INIT_SEVEN_SEG_PINS DDRC |= 0b01111111 ; DDRD|=0b00111111;
#define PORT_WRITE_PORTC PORTC
#define Disable_All_SS PORTD=0xff;
void SEVEN_SEG_init(void);
void SEVEN_SEG_write(uint8_t data,uint8_t num_ss);

#define EN1 CLRBIT(PORTD,0);
#define EN2 CLRBIT(PORTD,1);
#define EN3 CLRBIT(PORTD,2);
#define EN4 CLRBIT(PORTD,3);
#define EN5 CLRBIT(PORTD,4);
#define EN6 CLRBIT(PORTD,5);


#endif /* SEVEN_SEG_H_ */