/*
 * pwm_driver.c
 *
 *  Created on: Dec 5, 2023
 *      Author: Ahmed Sayed
 */

#include "pwm_driver.h"
#include <avr/io.h>
#include "Gpio.h"

/*
 * Configuration of Pwm with timer 0
 *
 * function arguments : Duty_Cycle to put this value in OCR0 To Give A wave form According Each Compare Match
 *
 */
void PWM_Timer0_Start(uint8 duty_cycle)
{
	TCCR0= (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
	TCNT0=0;
	OCR0=duty_cycle;
	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);
}

