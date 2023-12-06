/*
 * App.c
 *
 *  Created on: Dec 5, 2023
 *      Author: Ahmed Sayed
 */

#include "adc.h"
#include "dcmotor.h"
#include "lcd.h"
#include "Lm35_Sensor.h"
#include <util/delay.h>
/* This Function is static because it used only with App file and avoid any file to extern it  */
static void Permenant_Function(void) /* This Function is static That Responsible To Write The Permanent Messages on LCD */
{
	LCD_DisplayString(" INITILIZING ");
	_delay_ms(500);
	LCD_ClearScreen();
	LCD_displayStringRowColumn(0,0,"lOADING");
	_delay_ms(500);
	LCD_ClearScreen();
	_delay_ms(50);
	LCD_displayStringRowColumn(0,0,"FAN STATUS: ");
	LCD_displayStringRowColumn(1,0,"TEMP VAL=     C");

}
int main(void)
{
	uint8 temp_value=0;
	ADC_ConfigType config={Internal_REF_Voltage,PreScaler_div_8};
	ADC_Init(&config,Pooling);
	Dc_Motor_Init();
	LCD_init();
	Permenant_Function();

	for(;;)
	{
		temp_value=Get_Temp();
		if(temp_value<30)
		{
			Dc_MotorRotate(stopped,0);
			Move_Cursor(1,10);
			LCD_IntgerToString(temp_value);
			Move_Cursor(0,12);
			LCD_DisplayString("off");
		}
		else if(temp_value >=30 && temp_value<60 )
		{
			Dc_MotorRotate(clockwise,25);
			Move_Cursor(1,10);
			LCD_IntgerToString(temp_value);
			Move_Cursor(0,12);
			LCD_DisplayString("ON ");
		}
		else if(temp_value>=60 && temp_value<90)
		{
			Dc_MotorRotate(clockwise,50);
			Move_Cursor(1,10);
			LCD_IntgerToString(temp_value);
			Move_Cursor(0,12);
			LCD_DisplayString("ON ");
		}
		else if(temp_value>=90 && temp_value<120)
		{
			Dc_MotorRotate(clockwise,75);
			Move_Cursor(1,10);
			LCD_IntgerToString(temp_value);
			LCD_DisplayCharchter(' ');
			Move_Cursor(0,12);
			LCD_DisplayString("ON ");
		}

		else if(temp_value>=120)
		{
			Dc_MotorRotate(clockwise,100);
			Move_Cursor(1,10);
			LCD_IntgerToString(temp_value);
			Move_Cursor(0,12);
			LCD_DisplayString("ON ");
		}


	}

}


