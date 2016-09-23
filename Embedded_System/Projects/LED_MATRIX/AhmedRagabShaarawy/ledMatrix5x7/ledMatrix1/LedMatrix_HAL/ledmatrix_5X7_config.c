/*
 * ledmatrix_5X7_config.c
 *
 * Created: 9/22/2016 1:20:44 AM
 *  Author: AhmedShaarawy
 */ 

#include "ledmatrix_5X7_config.h"


/*
** led matrix configuration on kit.
*/
LedMatrix LMatrix= {
	.ColumnPort= A,
	.FirstColumnPin= 0,
	.RowPort= B,
	.FirstRowPin= 0
};