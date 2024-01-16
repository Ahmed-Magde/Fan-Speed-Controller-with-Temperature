/******************************************************************************
 *
 * Module: Fan Controller Mini Project 3
 *
 * File Name: Mini_Project3.c
 *
 * Description: Source file for the AVR Fan Controller
 *
 * Author: Ahmed Magdy
 *
 *******************************************************************************/

#include "lcd_driver.h"
#include "dc_motor.h"
#include "lm35.h"
#include <util/delay.h>


int main()
{

	uint8 temperature = 0;

	LM35_init();
	DcMotor_Init();
	LCD_init();




	LCD_displayStringRowColumn(0,6,"FAN");
	LCD_displayStringRowColumn(1,5,"CONTROL");
	_delay_ms(1500);
	LCD_clearScreen();

	while(1)
	{

		temperature = LM35_getRead();

		if(temperature < 30)
		{
			DcMotor_Rotate(OFF,0);
			LCD_displayStringRowColumn(0,3,"FAN IS OFF");

		}
		else if((temperature >= 30) && (temperature < 60))
		{
			DcMotor_Rotate(ON,25);
			LCD_displayStringRowColumn(0,3,"FAN IS ON  ");


		}
		else if((temperature >= 60) && (temperature < 90))
		{
			DcMotor_Rotate(ON,50);
			LCD_displayStringRowColumn(0,3,"FAN IS ON  ");

		}
		else if((temperature >= 90) && (temperature < 120))
		{
			DcMotor_Rotate(ON,75);
			LCD_displayStringRowColumn(0,3,"FAN IS ON  ");

		}
		else if((temperature >= 120) && (temperature <= 150))
		{
			DcMotor_Rotate(ON,100);
			LCD_displayStringRowColumn(0,3,"FAN IS ON  ");

		}




		LCD_displayStringRowColumn(1,3,"temp =    c");
		LCD_moveCursor(1,10);
		LCD_intgerToString(temperature);




	}


}
