/*
 * TimerModule.c
 *
 *  Created on: Apr 11, 2018
 *      Author: leenovoz510
 */
#include <avr/io.h>
#include <avr/delay.h>


void Timer0_PWM_Mode(unsigned int DutyCycle){
	TCNT0  = 0 ;
	OCR0   = DutyCycle;
	DDRB  |= (1<<PB3);  			  //set OC0 as output
	TCCR0 |= (1<<CS00) | (1<<CS02);   // 1024 Prescaler
	TCCR0 |= (1<<WGM00) | (1<<WGM01); // Fast PWM
	TCCR0 |= (1<<COM01); 			  // Reset OCR FAST PWM
}

void Timer2_PWM_Mode(unsigned int DutyCycle){
	TCNT2  = 0 ;
	OCR2   = DutyCycle;
	DDRD  |= (1<<PD7);  			  //set OC0 as output
	TCCR2 |= (1<<CS20) | (1<<CS22);   // 1024 Prescaler
	TCCR2 |= (1<<WGM21) | (1<<WGM20); // Fast PWM
	TCCR2 |= (1<<COM21); 			  // Reset OCR FAST PWM
}
