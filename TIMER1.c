/*
 * TIMER1.c
 *
 * Created: 9/11/2022 6:31:46 PM
 *  Author: walid
 */ 
#include "TIMER1.h"

void NORMAL_mod (void){
	SETBIT(TCCR1B , CS10); //NO prescale
	SETBIT(TCCR0,COM1A0);
	SETBIT(TIMSK , TOIE1);// interrupt enable
	SETBIT(TCCR1A,FOC1A);
	SETBIT(TCCR1A,FOC1B);
	
	SETBIT(SREG, 7);
	
}

/*void TIMER1_PWM_OC1A_init (void){
	SETBIT(DDRD  , 5 );    //make pin 5 in port D output
	SETBIT(TCCR1A ,COM1A1); //non-inverting mode 
	SETBIT(TCCR1B , WGM12); //Fast PWM 10-bit
	SETBIT(TCCR1A , WGM10); //Fast PWM 10-bit
	SETBIT(TCCR1A , WGM11); //Fast PWM 10-bit
	SETBIT(TCCR1B  , CS10);  //NO pre-scaling
	
}
/*
duty = (100/1024) * OCR1A
*/
/*
void TIMER1_PWM_OC1A_duty(uint8_t duty){
	OCR1A = duty * 10.23;
}*/