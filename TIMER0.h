/*
 * TIMER0.h
 *
 * Created: 21-Aug-22 9:50:23 PM
 *  Author: lenovo
 */ 

#include "std_macros.h"
#ifndef TIMER0_H_
#define TIMER0_H_

extern void (*timer0_ovf_isr)(void);
extern void (*timer0_ctc_isr)(void);

void TIMER0_normal_init(void);
void TIMER0_CTC_init(uint8_t oc);
void TIMER0_freqGen_init(uint8_t oc);



#endif /* TIMER0_H_ */