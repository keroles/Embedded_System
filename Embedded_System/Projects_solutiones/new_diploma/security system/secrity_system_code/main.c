/*
 * main.c
 *
 *  Created on: August 6, 2017
 *      Author: Amaero01
 */
#include <avr/io.h>
#include <util/delay.h>
#include "port.h"
#include "switch.h"
#include "sevenSegment.h"
#include "led.h"
int main(void)
{
	switch_init();
	led_init();
	SS_init();
	for(;;)
	{
		switch(checkPressedSwitch())
		{
		case Ones_SS:
			increment_ones();
			break;
		case Tens_SS:
			increment_tens();
			break;
		case Enter:
			switch(counts_number())
			{
			case PASS:
				SET_LED_STATE(PORTA, GREEN_LED, ON);
				break;
			case WRONG:
				ALARM();
				break;
			}
			break;
		default:
			seven_segment_display(count_ones, ones_enable);
			_delay_ms(40);
			seven_segment_display(count_tens, tens_enable);
			_delay_ms(40);
			break;
		}
	}
	return 0;
}
