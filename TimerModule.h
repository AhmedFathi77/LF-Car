/*
 * TimerModule.h
 *
 *  Created on: Apr 11, 2018
 *      Author: leenovoz510
 */

#ifndef TIMERMODULE_H_
#define TIMERMODULE_H_
void Timer0_PWM_Init();
void Timer2_PWM_Init();
void Timer0_PWM_Mode(unsigned int DutyCycle);
void Timer2_PWM_Mode(unsigned int DutyCycle);

#endif /* TIMERMODULE_H_ */
