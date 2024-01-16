/*
 * lm35.c
 *
 *  Created on: Oct 6, 2021
 *      Author: Ahmed Magdy
 */


#include "lm35.h"
#include "adc.h"


void LM35_init(void)
{
	ADC_ConfigType  ADC_Config = {INTERNAL_2_5V ,F_CPU8 };
	ADC_init(&ADC_Config);

}

uint8 LM35_getRead(void)
{
	uint8 temp_val;
	uint16 adc_val;

	adc_val=ADC_readChannel(LM35_ADC_CHANNAL_NUM);
	temp_val = (uint8)(((float32)adc_val*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));
	return temp_val;
}















