/*
 * dcmotor.h
 *
 *  Created on: Dec 5, 2023
 *      Author: Ahmed Sayed
 */

#ifndef DCMOTOR_H_
#define DCMOTOR_H_
#include "std_types.h"
#define Max_Timer0 256 /* Maximum Value for Timer 0 */

/*
 *     // Enum For State of Dc_Motor//
 */
typedef enum
{
	anticlock_wise=-1,stopped=0,clockwise=1

}DcMotor_state;


void Dc_Motor_Init(void);

void Dc_MotorRotate(DcMotor_state state,uint8 speed);

#endif /* DCMOTOR_H_ */
