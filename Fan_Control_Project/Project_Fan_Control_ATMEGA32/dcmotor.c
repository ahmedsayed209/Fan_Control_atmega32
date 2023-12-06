/*
 * dcmotor.c
 *
 *  Created on: Dec 5, 2023
 *      Author: Ahmed Sayed
 */

#include"dcmotor.h"
#include "Gpio.h"
#include "pwm_driver.h"

/*
 *     Initialization For Dc_Motor To Just configure The Pins for Motor
 */
void Dc_Motor_Init(void)
{
	GPIO_setupPinDirection(PORTB_ID,PIN0_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN1_ID,PIN_OUTPUT);
	GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
	GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW);
}

/*
 *  Initialization for Dc_Motor To Read The State of Rotation of Motor
 *  Speed of motor is choose according to condition and passed to Pwm function to generate a duty cycle wave
 */

void Dc_MotorRotate(DcMotor_state state,uint8 speed)
{
	uint8 nedded_cycle=0;
	nedded_cycle=((speed*Max_Timer0)/100);
	PWM_Timer0_Start(nedded_cycle);
	switch(state)
	{
	case anticlock_wise:
		GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_HIGH);
		GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW);
		break;
	case clockwise:
		GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
		GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_HIGH);
		break;
	case stopped:
		GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
		GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW);
		break;


	}
}
