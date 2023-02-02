/*
 * TIMER1.h
 *
 * Created: 9/11/2022 6:32:09 PM
 *  Author: walid
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_
#include "std_macros.h"
void TIMER1_PWM_OC1A_init (void);
void TIMER1_PWM_OC1A_duty(uint8_t duty);
void NORMAL_mod (void);



#endif /* TIMER1_H_ */