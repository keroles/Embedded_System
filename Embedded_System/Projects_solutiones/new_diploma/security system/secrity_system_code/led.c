/*
 * led.c
 *
 *  Created on: August 8, 2017
 *      Author: Amaero01
 */
#include <avr/io.h>
#include "led.h"

void led_init(void)
{
	DDRA |= ((1<<GREEN_LED) | (1<<YELLOW_LED) | (1<<RED_LED) | (1<<BUZZER));
	PORTA = 0xFF;
}
