/*
 * adc.c
 *
 *  Created on: Oct 5, 2021
 *      Author: Ahmed Magdy
 */

#include "adc.h"
#include <avr/io.h>
#include "common_macros.h"
#include <avr/interrupt.h>



#ifdef ADC_by_interrupet

static volatile uint16  ADC_VALUE=0;


ISR(ADC_vect)
{
	ADC_VALUE = ADC;
}

void ADC_init_by_interrupet(void)
{
	ADMUX=0;
	ADCSRA|=(1<<ADEN)|(1<< ADPS1)|(1<<ADIE)|(1<<ADATE);
}

uint16 ADC_readChannel_interrupt(uint8 channel_num)
{
	ADMUX = (ADMUX & 0xe0) | (channel_num & 0x07);
	SET_BIT(ADCSRA,ADSC);
	return ADC_VALUE;
}

#else

void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	ADMUX = (ADMUX & 0X3F) | ((Config_Ptr->ref_volt) <<6);
	ADCSRA = (ADCSRA & 0XF8) | (Config_Ptr->prescaler);
	ADCSRA|=(1<<ADEN);
}


uint16 ADC_readChannel(uint8 channel_num)
{


	ADMUX = (ADMUX & 0XE0) | (channel_num & 0x07);
	SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it :) */
	return ADC; /* Read the digital value from the data register */
}


#endif




