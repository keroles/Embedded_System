/*
 * keybad_4_4.c
 *
 *  Created on: Aug 11, 2017
 *      Author: Keroles Shenouda
 */


#include "keypad.h"
int Key_padRow[] = {R0, R1, R2, R3}; //rows of the keypad
int Key_padCol[] = {C0, C1, C2, C3};//columnd
void  Keypad_init()
{
	keypadDDR &= ~ (1<<R0)|(1<<R1)|(1<<R2)|(1<<R3);//set upper part of keypad port as input
	//this will be required for scanning the rows
	keypadDDR |= ((1<<C0)|(1<<C1)|(1<<C2)|(1<<C3));//set lower part of keypad port as output.This is
	//the part of the keypad port where the rows are connected.
	keypadPORT = 0xFF ;
}



char Keypad_getkey()
{
	int i, j;
	for(i = 0; i < 4; i++)
	{
		keypadPORT |= ((1<<Key_padCol[0] ) | (1<<Key_padCol[1] ) | (1<<Key_padCol[2] ) | (1<<Key_padCol[3] ));

		keypadPORT &= ~ (1 << Key_padCol[i]);//send a low to a particular row of the keypad

		for(j = 0; j < 4; j++)
		{
			if(!(keypadPIN & (1<<Key_padRow[j])))//check if key is pressed
			{
				while(!(keypadPIN & (1<<Key_padRow[j])));  //wait for key to be released  (Single press)
				switch(i)
				{
				case(0):
                	{
					if (j == 0) return '7';
					else if (j == 1) return '4';
					else if (j == 2) return '1';
					else if (j == 3) return '?';
					break;
                	}
				case(1):
                	{
					if (j == 0) return '8';
					else if (j == 1) return '5';
					else if (j == 2) return '2';
					else if (j == 3) return '0';
					break;
                	}
				case(2):
                	{
					if (j == 0) return '9';
					else if (j == 1) return '6';
					else if (j == 2) return '3';
					else if (j == 3) return '=';
					break;
                	}
				case(3):
                	{
					if (j == 0) return '/';
					else if (j == 1) return '*';
					else if (j == 2) return '-';
					else if (j == 3) return '+';
					break;
                	}
				}
			}
		}
	}
	return 'A';//Return 'A' if no key is pressed.
}
