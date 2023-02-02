/*
 * WATCH_APP(new).c
 *
 * Created: 16-Sep-22 1:40:08 PM
 * Author : lenovo
 */ 

#include "LCD.h"
#include "SEVEN_SEG.h"
#include "TIMER1.h"
#include "TIMER0.h"
#include "KEYPAD.h"

static void ctc_isr (void);
uint8_t get_key();
void watch_edit();
void lcd_update();
uint8_t static count =0,count1=0;
volatile uint8_t sec=0, min= 0,hr=0;
uint8_t flag=0;

int main(void)
{
	SEVEN_SEG_init();
	KEYPAD_init();
	NORMAL_mod();
	TIMER0_CTC_init(124);
	timer0_ctc_isr = ctc_isr;
	LCD_init();
    //timer0_ovf_isr = ovf_isr;
	
    /* Replace with your application code */
    
	while (1) 
    {
		uint8_t keypad_key = KEYPAD_read();
		lcd_update();
		if (min==60)
		{
			min=0;
			hr++;
		}
		
		if (keypad_key =='c')
		{
			flag =1;
			while(KEYPAD_read() == 'c');
			while(KEYPAD_read()==0);
			keypad_key = KEYPAD_read();
			while(keypad_key!='c')
			{
				if (keypad_key=='+')
				{
					if (min==59)
					{
						min=0;
					}
					min++;
					lcd_update();
					while(KEYPAD_read() == '+');
				}
				else if(keypad_key=='-')
				{
					if (min == 0)
					{
						min=59;
					}
					min--;
					lcd_update();
					while(KEYPAD_read() == '-');
				}
				keypad_key = KEYPAD_read();
			}
			while(KEYPAD_read() == 'c');
			while(KEYPAD_read()==0);
			keypad_key = KEYPAD_read();
			while(keypad_key!='c')
			{
				if (keypad_key=='+')
				{
					if (hr==24)
					{
						hr=0;
					}
					hr++;
					lcd_update();
					while(KEYPAD_read() == '+');
				}
				else if(keypad_key=='-')
				{
					if (hr == 0)
					{
						hr=24;
					}
					hr--;
					lcd_update();
					while(KEYPAD_read() == '-');
				}
				keypad_key = KEYPAD_read();
			
			}
			flag =0;
			
			while(KEYPAD_read() == 'c');
		//	while(KEYPAD_read()==0);	
		}
	}
	
}
/*
c.c = 1/16 usec
prescaler = 1024
cr = 124 
ov_time = (cr* 64) usec
1sec =  ov_time * count
count = 15625/cr = 125

cr = 125 ===> count = 125
*/
void lcd_update(void)
{
	LCD_write_command(0x80);
	LCD_write_num(hr);
	LCD_write_string(":");
	LCD_write_num(min);
	LCD_write_string(":");
	LCD_write_num(sec);
}
void watch_edit()
{		
		
	uint8_t change_clk = get_key();
	if(change_clk == '+')
	{
		//sec=0;
		min = min +10;
		
	}
	else if (change_clk=='-')
	{
		min = min-10;
		
	}
}
/*
uint8_t get_key()
{
	uint8_t key;
	key = KEYPAD_read();
	while(key==0)
	{
		key=KEYPAD_read();
	}
	while(KEYPAD_read()==key);
	return key;
}*/
static void ctc_isr(void){
	static uint8_t seven_seg_select =0;
	
	count1++;
	if(count1 ==128)
	{
	
	switch(seven_seg_select){
				
		case 0: SEVEN_SEG_write(sec/10,1); seven_seg_select++;break;
		case 1: SEVEN_SEG_write(sec%10,2); seven_seg_select++;break;
		case 2: SEVEN_SEG_write(min/10,3); seven_seg_select++;break;
		case 3: SEVEN_SEG_write(min%10,4); seven_seg_select++;break;
		case 4: SEVEN_SEG_write(hr/10,5);  seven_seg_select++;break;
		case 5: SEVEN_SEG_write(hr%10,6); seven_seg_select=0; break;
		
	}
	
	count1=0;
	}

}



ISR(TIMER1_OVF_vect){
	if (flag==0)
	{
	
	count++;
	if(count == 244){
		sec++;
		if (sec==60)
		{
		sec=0;
		min++;
		}
		count=0;
		
	}
	
	}
}