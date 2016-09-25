/*
 * LCD_Led.h
 *
 * Created: 9/18/2016 3:07:31 PM
 *  Author: Mohamed Abo Arab
 */ 


#ifndef LCD_LED_H_
#define LCD_LED_H_


#define myPORTA  *((volatile unsigned char* const)0X3B)
#define myDDRA   *((volatile unsigned char* const)0X3A)
#define myPINA   *((volatile unsigned char* const)0X39)
#define myPORTB  *((volatile unsigned char* const)0X38)
#define myDDRB   *((volatile unsigned char* const)0X37)
#define myPINB   *((volatile unsigned char* const)0X36)
#define myPORTC  *((volatile unsigned char* const)0X35)
#define myDDRC   *((volatile unsigned char* const)0X34)
#define myPINC   *((volatile unsigned char* const)0X33)
#define myPORTD  *((volatile unsigned char* const)0X32)
#define myDDRD   *((volatile unsigned char* const)0X31)
#define myPIND   *((volatile unsigned char* const)0X30)

void mydelay10ms(unsigned long time);
void Draw_char(unsigned char fram,unsigned char letter);


#endif /* LCD_LED_H_ */