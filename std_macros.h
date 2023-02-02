/*
 * std_macros.h
 *
 * Created: 8/7/2022 11:45:51 AM
 *  Author: Aliaa
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_


#include <avr/io.h>   // this file include all register addresses macros like DDRA
#define F_CPU 16000000UL // set the frequency of micro-controller
#include <util/delay.h> // this header include all delay function like _delay_ms
#include <avr/interrupt.h> // this header is necessary when you deal with interrupt

#define SETBIT(REG,BIT) (REG |=1<<BIT)
#define CLRBIT(REG,BIT) (REG &= ~(1<<BIT))
#define TOGBIT(REG,BIT) (REG ^= 1<<BIT)
#define READBIT(REG,BIT) ((REG >> BIT) & 1)


#endif /* STD_MACROS_H_ */