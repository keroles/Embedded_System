/*
 * LCD.h
 *
 * Created: 10/28/2016 11:59:08 PM
 *  Author: loma
 */ 


#ifndef LCD_H_
#define LCD_H_

#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 1000000ul

 
#define RS PD4
#define	RW PD5
#define EN PD6

#define MrLCD_Control_Port PORTD
#define MrLCD_Control_Port_DIR DDRD
#define MrLCD_DATA_Port PORTC
#define MrLCD_DATA_Port_DIR DDRC
#define CLEAR_BIT(REG,BIT) (REG &= ~(1<<BIT))
#define SET_BIT(REG,BIT) (REG |= (1<<BIT))



void LCD_init(void);
void LCD_SendCommand(unsigned char command);
void LCD_SendChar(unsigned char data);
void LCD_DisplayString(char *Str);
void LCD_GoTo_XY(unsigned char row,unsigned char col);
void LCD_ClearScreen(void);
void LCD_DisplayString_ATXY(unsigned char row,unsigned char col,char *str);
void Int_TO_String(int data);

void check_LCD_isbusy(void);


#endif /* LCD_H_ */