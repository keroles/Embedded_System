/*
 * ledmatrix_5X7_config.h
 *
 * Created: 9/22/2016 1:21:34 AM
 *  Author: AhmedShaarawy
 */ 


#ifndef LEDMATRIX_5X7_CONFIG_H_
#define LEDMATRIX_5X7_CONFIG_H_

#include "atmega32_IO.h"

typedef struct  
{
	U8 RowPort;
	U8 FirstRowPin;
	U8 ColumnPort;
	U8 FirstColumnPin;
} LedMatrix;

extern LedMatrix LMatrix ;


#endif /* LEDMATRIX_5X7_CONFIG_H_ */