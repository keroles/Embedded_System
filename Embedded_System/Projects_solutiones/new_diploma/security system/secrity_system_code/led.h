/*
 * led.h
 *
 *  Created on: August 8, 2017
 *      Author: Amaero01
 */
#include "port.h"
#define GREEN_LED		(0)
#define YELLOW_LED		(1)
#define RED_LED			(2)
#define BUZZER			(3)
#ifndef LED_H_
#define LED_H_
typedef enum
{
	ON,
	OFF
}LED_T;

#define SET_LED_STATE(PORT, PIN, STATE)		((STATE == ON) ? (SET_BIT(PORT, PIN)) : (CLEAR_BIT(PORT, PIN)))
#define SET_BUZZER_STATE(PORT, PIN, STATE)		((STATE == ON) ? (SET_BIT(PORT, PIN)) : (CLEAR_BIT(PORT, PIN)))
void led_init(void);
#endif /* LED_H_ */
