/*
 * TIMER0.c
 *
 * Created: 21-Aug-22 9:50:34 PM
 *  Author: lenovo
 */ 
#include "TIMER0.h"
void (*timer0_ovf_isr)(void);
void (*timer0_ctc_isr)(void);

void TIMER0_normal_init(void)
{
	SETBIT(TCCR0,COM00); //No pre-scaler
	SETBIT(TCCR0,FOC0);
	SETBIT(TIMSK,TOIE0);//overflow interrupt
	SETBIT(SREG, 7); // enable global interrupt
	
}
void TIMER0_CTC_init(uint8_t oc){
	SETBIT(TCCR0,CS00); // PRESCALER
	//SETBIT(TCCR0,CS02); // PRESCALER 1024
	SETBIT(TCCR0,FOC0);
	SETBIT(TCCR0,WGM01); // CTC
	OCR0 = oc;
	SETBIT(TIMSK,OCIE0); // enable timer ctc interrupt
	SETBIT(SREG, 7); // enable global interrupt
}
/*
void TIMER0_CTC_init(uint8_t oc)
{
	SETBIT(TCCR0,WGM01); //turn on CTC mode
	SETBIT(TCCR0,CS00);
	//SETBIT(TCCR0,CS02); //pre-scaler on 1024
	SETBIT(TIMSK,OCIE0);// enable timer ctc interrupt
	SETBIT(TCCR0,COM00); // toggle
	SETBIT(SREG, 7); // enable global interrupt
	OCR0 = oc;
	SETBIT(TCCR0,FOC0);
}
void TIMER0_freqGen_init(uint8_t oc)
{
	SETBIT(DDRB, 3); // set OC0 as output
	SETBIT(TCCR0,CS00); // PRESCALER
	//SETBIT(TCCR0,CS02); // pre-scaler on 256
	SETBIT(TCCR0,FOC0);//equals to one as it is a ctc mode not PWM
	SETBIT(TCCR0,WGM01); // CTC
	OCR0 = oc;
	SETBIT(TCCR0,COM00);
}*/

ISR(TIMER0_OVF_vect){
	timer0_ovf_isr();
}

ISR(TIMER0_COMP_vect){
	timer0_ctc_isr();
}