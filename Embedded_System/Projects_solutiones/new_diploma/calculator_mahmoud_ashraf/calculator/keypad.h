/*
 * keypad.h
 *
 *  Created on: Aug 11, 2017
 *      Author: Keroles Shenouda
 */

#ifndef KEYPAD_KEYPAD_H_
#define KEYPAD_KEYPAD_H_

#include <avr/io.h>
#include<util/delay.h>



//Keypad Information0
#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 0
#define C1 1
#define C2 2
#define C3 3
#define C4 4
#define C5 5
#define keypadPORT_r PORTC
#define keypadPIN_r PINC
#define keypadDDR_r DDRC

#define keypadPORT_c PORTD
#define keypadPIN_c PIND
#define keypadDDR_c DDRD

//Keypad functions and global variables

#define CLC 'A'
#define AOP 'B'
#define OP1 'C'
#define OP2 'D'
#define OP3 'E'
#define OP4 'F'
#define OP5 'G'
#define OP6 'H'
#define OP7 'I'
#define OP8 'J'
#define OP9 'K'
#define NO_KEY 'Z'


void  Keypad_init();
char Keypad_getkey();

#endif /* KEYPAD_KEYPAD_H_ */
