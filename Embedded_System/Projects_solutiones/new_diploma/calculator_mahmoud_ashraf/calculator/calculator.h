/*
 * IncFile1.h
 *
 * Created: 8/3/2018 1:59:24 PM
 *  Author: Mahmoud Ashtaf
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_


/*============================================================================*/
/*============================================================================*/

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include "keypad.h"
#include <util/delay.h>
typedef char bool;
#define true 1
#define false 0

/*============================================================================*/
/*===============================used Functions ==============================*/


void print_intro();				   	   //print intro message on LCD
void print_modes();					   // display Available modes in calculator
void intro_interface();				   // control All actions before select mode
void get_mode();						   // allow the user to select mode
void Arth_mode();						   //Main Function in Arth Mode
void logic_mode();
void Detect_numbers();					   //convert the input numbers from keypad to integer
void swap_operation();					   // multi push swap operation as + - * /
void save_last_number();				   // store the input from user in input array
void save_last_OP();					   // store the Operation from user in operation array
void calculate ();					 	   // Use the input array and operation array to calculate results
void Print_result ();				       //Display the result
void reset_var();                         // Init all Variables At end of operation
void init_addtion_op();
void disp_addition_op();




#endif /* INCFILE1_H_ */