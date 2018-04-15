/*
 * main.c
 *
 *  Created on: Apr 11, 2018
 *      Author: leenovoz510
 */
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#include "TimerModule.h"
#include "L293D.h"
#include "LCD.h"
#include "GlobalVars.h"

#define Trigger_Pin PB1
#define Echo_Pin	PD2
int Distance = 0 , EndTime = 0;

void Interrupt_init(){
	MCUCR |= (1<<ISC10);
	GICR  |= (1<<INT0);
}

void Ultrasonic_init(){
	DDRB |= (1<<Trigger_Pin);
	DDRD &= ~(1<<Echo_Pin);
	PORTD |= (1<<Echo_Pin);
	Interrupt_init();
	Timer1_Overflow_Mode();
}

void Ultrasonic_Trigger(){
	PORTB &= ~(1<<Trigger_Pin);
	_delay_ms(10);
	PORTB |=  (1<<Trigger_Pin);
	_delay_ms(10);
	PORTB &= ~(1<<Trigger_Pin);
}

ISR(TIMER1_OVF_vect){
	OverFlow_Var++;
}
ISR(INT1_vect){
	if( (PIND&(1<<Echo_Pin)) == 0){
		TCNT1 = 0;
	}else if((PIND&(1<<Echo_Pin)) == 1){
		EndTime = (TCNT1/2)+(OverFlow_Var*65535);
		Distance = EndTime/466.47;
		Go_to(2 ,2);
		Number_ScreenPrint(Distance);
	}
}
int main(void){

	DDRA|= (1<<PA0) | (1<<PA1) | (1<<PA2) | (1<<PA3);


	DDRC = 0XFF;	    // Data Pins OF LCD
		DDRA |=(1<<PA5);	// EN as Input
		DDRA |=(1<<PA6);	// RS
		DDRA |=(1<<PA7);	// RW
	 LCD_Init();
	_delay_ms(10);
	LCD_Clear();
	sei();
	Ultrasonic_init();
	while(1){
		Go_to(1 , 1);
		LCD_ScreenPrint("Distance is: ");
		Ultrasonic_Trigger();
		_delay_ms(1);

	}

}

