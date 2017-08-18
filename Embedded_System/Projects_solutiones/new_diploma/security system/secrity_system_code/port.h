/*
 * port.h
 *
 *  Created on: August 8, 2017
 *      Author: Amaero01
 */

#ifndef PORT_H_
#define PORT_H_
#define SET_BIT(PORT_NAME, PIN_NUMBER)		(PORT_NAME &= ~(1<<PIN_NUMBER))
#define CLEAR_BIT(PORT_NAME, PIN_NUMBER)	(PORT_NAME |= (1<<PIN_NUMBER))
#define CHECK_PB(PIN_NAME, PIN_NUMBER)		(PIN_NAME & (1 << PIN_NUMBER))
#endif /* PORT_H_ */
