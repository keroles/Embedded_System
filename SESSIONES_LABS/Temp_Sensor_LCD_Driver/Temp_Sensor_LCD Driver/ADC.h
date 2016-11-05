/*
 * ADC.h
 *
 * Created: 11/2/2016 8:58:06 PM
 *  Author: loma
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>

void ADC_Init(void);
unsigned short ADC_Read(unsigned char channel_num);


#endif /* ADC_H_ */