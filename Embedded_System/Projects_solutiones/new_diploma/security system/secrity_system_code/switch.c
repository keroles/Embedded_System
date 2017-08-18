/*
 * switch.c
 *
 *  Created on: August 8, 2017
 *      Author: Amaero01
 */
#include <avr/io.h>
#include <util/delay.h>
#include "switch.h"
#include "led.h"
int led_number;
void switch_init(void)
{
	DDRB &= ~((1<<ONES_PB) | (1<<TENS_PB) | (1<<ENTER));
	PORTB = 0xFF;
}
SWITCH_T checkPressedSwitch(void)
{
	SWITCH_T Push_Button = None_PB_Pressed;
	if(!CHECK_PB(PINB, ONES_PB))
	{
		while(!CHECK_PB(PINB, ONES_PB));
		Push_Button = Ones_SS;
	}
	else if(!CHECK_PB(PINB, TENS_PB))
	{
		while(!CHECK_PB(PINB, TENS_PB));
		Push_Button = Tens_SS;
	}
	else if(!CHECK_PB(PINB, ENTER))
	{
		while(!CHECK_PB(PINB, ENTER));
		Push_Button = Enter;
	}
	return Push_Button;
}
void ALARM(void)
{
	do{
		for(led_number = 0; led_number < 4; led_number++)
		{
			PORTA = ~(1<<led_number);
			SET_BUZZER_STATE(PORTA, BUZZER, ON);
			_delay_ms(500);
			if(!CHECK_PB(PINB, ENTER))
			{
				while(!CHECK_PB(PINB, ENTER));
				PORTA = 0xFF;
				return;
			}
		}
	}while(1);
}

