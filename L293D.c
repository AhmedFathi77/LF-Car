/*
 * L293D.c
 *
 *  Created on: Apr 12, 2018
 *      Author: leenovoz510
 */
#include <avr/io.h>
#include <avr/delay.h>
#include "TimerModule.h"

void Car_StopMoving(){				// Stop moving
	Timer2_PWM_Mode(2);
	PORTA &= ~(1<<PA0);
	PORTA &= ~(1<<PA1);
	_delay_ms(40);
	Timer0_PWM_Mode(2);
	PORTA &= ~(1<<PA2);
	PORTA &= ~(1<<PA3);
	_delay_ms(40);
}
void Car_MoveForward(){		// Move   ClockWise
	//Left Side Motors
	Timer2_PWM_Mode(255);
	PORTA &= ~(1<<PA0);
	PORTA |=  (1<<PA1);
	_delay_ms(40);
	//Right Side Motors
	Timer0_PWM_Mode(255);
	PORTA &= ~(1<<PA2);
	PORTA |=  (1<<PA3);
	_delay_ms(40);
}

void Car_MoveLeft(){ 	// Move Anti ClockWise
	//Right Side Motors
	Timer2_PWM_Mode(255);		//Right Motors
	PORTA |=  (1<<PA0);
	PORTA &= ~(1<<PA1);
	_delay_ms(40);
	//Left Side Motors
	Timer0_PWM_Mode(64);		//Left Motors
	PORTA &= ~(1<<PA2);
	PORTA |=  (1<<PA3);
	_delay_ms(40);
}


void Car_MoveRight(){		// Move   ClockWise
	//Left Side Motors
	Timer2_PWM_Mode(64);		//Right Motors
	PORTA &= ~(1<<PA0);
	PORTA |=  (1<<PA1);
	_delay_ms(40);
	//Right Side Motors
	Timer0_PWM_Mode(255);		//Left Motors
	PORTA &= ~(1<<PA2);
	PORTA |=  (1<<PA3);
	_delay_ms(40);
}
