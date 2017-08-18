/*
 * switch.h
 *
 *  Created on: August 8, 2017
 *      Author: Amaero01
 */
#include "port.h"
#define ONES_PB			(0)
#define TENS_PB			(1)
#define ENTER			(2)
#ifndef SWITCH_H_
#define SWITCH_H_
typedef enum
{
	None_PB_Pressed,
	Ones_SS,
	Tens_SS,
	Enter
}SWITCH_T;
SWITCH_T checkPressedSwitch(void);
void switch_init(void);
void ALARM(void);
#endif /* SWITCH_H_ */
