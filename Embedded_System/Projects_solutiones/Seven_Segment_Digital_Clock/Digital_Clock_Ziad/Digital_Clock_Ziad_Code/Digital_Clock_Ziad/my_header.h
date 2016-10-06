/*
 * my_header.h
 *
 * Created: 10/1/2016 11:07:31 PM
 *  Author: Ziad-Khater
 */ 


#ifndef MY_HEADER_H_
#define MY_HEADER_H_

#define MYDDRD *((volatile unsigned char* const) 0x31 )
#define MYPIND *((volatile unsigned char* const) 0x30 )
#define MYPORTD *((volatile unsigned char* const) 0x32 )
#define MYDDRC *((volatile unsigned char* const) 0x34 )
#define MYPINC *((volatile unsigned char* const) 0x33 )
#define MYPORTC *((volatile unsigned char* const) 0x35 )

#define u8 unsigned char


//void mydelay (unsigned long time);
//void clock_edit(void); 


#endif /* MY_HEADER_H_ */