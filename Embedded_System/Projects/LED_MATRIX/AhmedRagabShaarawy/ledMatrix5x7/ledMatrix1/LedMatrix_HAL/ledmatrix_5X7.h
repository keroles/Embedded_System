/*
 * ledmatrix_5X7.h
 *
 * Created: 9/22/2016 1:02:52 AM
 *  Author: AhmedShaarawy
 */ 


#ifndef LEDMATRIX_5X7_H_
#define LEDMATRIX_5X7_H_

#include "ledmatrix_5X7_config.h"

#define TRUE_ALPHA(ASCII)		( ASCII>=65 && ASCII<=90 )
#define TRUE_DIGIT(ASCII)		( ASCII>=48 && ASCII<=57 )
#define TRUE_DELAY(Dtime)		( Dtime<= 65535 )
#define TRUE_ROWPIN(pin)		( pin < 2 )
#define TRUE_COLUMNPIN(pin)		( pin < 4 )

U8 LMTRX5x7_DrawAlpha( U8 alpha, U16 timeDelay_ms );
U8 LMTRX5x7_DrawDigit( U8 alpha, U16 timeDelay_ms );


#endif /* LEDMATRIX_5X7_H_ */