/*
 * dc_motor.c
 *
 *  Created on: Oct 7, 2021
 *      Author: Ahmed Magdy
 */

#include "dc_motor.h"
#include "gpio.h"
#include "pwm.h"

void DcMotor_Init(void)
{
	PWM_Clock pwm_clock = {F_CPU_8};

	PWM_Init(pwm_clock);


	GPIO_setupPinDirection( DcMotor_IN_PORT, DcMotor_IN1_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection( DcMotor_IN_PORT, DcMotor_IN2_PIN, PIN_INPUT);

	GPIO_setupPinDirection( DcMotor_EN_PORT, DcMotor_EN_PIN, PIN_OUTPUT);
	PWM_setDuty(0);

}

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	if(state==CW)
	{
		GPIO_setupPinDirection( DcMotor_IN_PORT, DcMotor_IN1_PIN, PIN_INPUT);
		GPIO_setupPinDirection( DcMotor_IN_PORT, DcMotor_IN2_PIN, PIN_OUTPUT);

		PWM_setDuty(speed);
	}
	else if(state==A_CW)
	{
		GPIO_setupPinDirection( DcMotor_IN_PORT, DcMotor_IN1_PIN, PIN_OUTPUT);
		GPIO_setupPinDirection( DcMotor_IN_PORT, DcMotor_IN2_PIN, PIN_INPUT);

		PWM_setDuty(speed);
	}
	else if(state==STOP)
	{
		GPIO_setupPinDirection( DcMotor_IN_PORT, DcMotor_IN1_PIN, PIN_INPUT);
		GPIO_setupPinDirection( DcMotor_IN_PORT, DcMotor_IN2_PIN, PIN_INPUT);

		PWM_setDuty(speed);
	}

}















