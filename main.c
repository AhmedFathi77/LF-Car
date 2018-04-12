/*
 * main.c
 *
 *  Created on: Apr 11, 2018
 *      Author: leenovoz510
 */
#include <avr/io.h>
#include <avr/delay.h>
#include "TimerModule.h"
#include "L293D.h"

void Ultrasonic_Trigger(){
	PORTB |=  (1<<PB1);
	_delay_ms(10);
	PORTB &= ~(1<<PB1);
}

int main(void){

	DDRA|= (1<<PA0) | (1<<PA1) | (1<<PA2) | (1<<PA3);
	DDRB |= (1<<PB1);	//Trigger Pin
	DDRC = 0XFF;	    // Data Pins OF LCD
	while(1){
		Car_MoveForward();
		_delay_ms(10000);
		Car_StopMoving();
		_delay_ms(30000);

	}

}

