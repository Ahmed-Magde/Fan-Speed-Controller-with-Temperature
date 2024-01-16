/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Ahmed Magdy
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_by_interrupet
#undef ADC_by_interrupet

#define ADC_MAXIMUM_VALUE    1023.0
#define ADC_REF_VOLT_VALUE   2.56



typedef enum
{
	AREF,AVCC_WITH_EXTERNAL_AREF,RESERVED,INTERNAL_2_5V
}ADC_ReferenceVolatge;

typedef enum
{
	F_CPU2=1,F_CPU4,F_CPU8,F_CPU16,F_CPU32,F_CPU64,F_CPU128
}ADC_Prescaler;

typedef struct{
 ADC_ReferenceVolatge ref_volt;
 ADC_Prescaler prescaler;
}ADC_ConfigType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
#ifdef ADC_by_interrupet

void ADC_init_by_interrupet(void);
uint16 ADC_readChannel_interrupt(uint8 channel_num);

#else

void ADC_init(const ADC_ConfigType * Config_Ptr);
uint16 ADC_readChannel(uint8 channel_num);
#endif


#endif /* ADC_H_ */
