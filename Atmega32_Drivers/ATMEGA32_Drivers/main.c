/*
 * main.c
 *
 *  Created on: Aug 4, 2017
 *      Author: Keroles Shenouda
 *      https://www.facebook.com/groups/embedded.system.KS/
 */

#include "GPIO/GPIO.h"
#include "mydelay.h"
#define output 1
#define input 0

int main ()
{
	GPIO_voidInit();
	GPIO_u8_WritePinDir(5,output,'D') ;
	int toggle_led = 1;
	while(1)
	{
		GPIO_u8_WritePinVal(5,toggle_led,'D') ;
		toggle_led ^= 1 ;
		DELAY_MS(1000);
	}

	return 0 ;
}
