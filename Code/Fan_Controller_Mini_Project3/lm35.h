/*
 * lm23.h
 *
 *  Created on: Oct 6, 2021
 *      Author: Ahmed Magdy
 */

#ifndef LM35_H_
#define LM35_H_

#include "std_types.h"




#define LM35_ADC_CHANNAL_NUM	2
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150.0



void LM35_init(void);
uint8 LM35_getRead(void);
#endif /* LM35_H_ */
