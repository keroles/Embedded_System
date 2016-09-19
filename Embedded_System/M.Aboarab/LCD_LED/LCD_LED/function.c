/*
 * function.c
 *
 * Created: 9/19/2016 10:16:19 PM
 *  Author: Mohamed Abo Arab
 */ 
  #include "LCD_Led.h"
  void mydelay10ms(unsigned long time)
  {
	  while(time>0)
	  {
		  volatile int long i=1500;
		  while(i>0)
		  {
			  i--;
		  }
		  time--;
	  }
  }
  
  void Draw_char(unsigned char fram,unsigned char letter)
  {
	  if(fram==0)
	  {
		  switch(letter){
			  case'A':
			  
			  myPORTA=0b01110010;
			  myPORTB=0b01010101;
			  mydelay10ms(30);
			  myPORTA=myPORTB=0x00;
			  mydelay10ms(30);
			  break;
			  
			  case'B':
			  
			  myPORTA=0b01100110;
			  myPORTB=0b00000110;
			  mydelay10ms(30);
			  myPORTA=myPORTB=0x00;
			  mydelay10ms(30);
			  break;
			  
			  case'C':
			  
			  
			  myPORTA=0b01000011;
			  myPORTB=0b01110100;
			  mydelay10ms(30);
			  myPORTA=myPORTB=0x00;
			  mydelay10ms(30);
			  break;
			  
			  
			  case'D':
			  
			  myPORTA=0b01010110;
			  myPORTB=0b01100101;
			  mydelay10ms(30);
			  myPORTA=myPORTB=0x00;
			  mydelay10ms(30);
			  break;
			  
			  
			  case'E':
			  
			  myPORTA=0b01110111;
			  myPORTB=0b00000111;
			  mydelay10ms(30);
			  myPORTA=myPORTB=0x00;
			  mydelay10ms(30);
			  break;
			  
			  default:
			  myPORTA=myPORTB=0xff;
			  break;
		  }
	  }
	  
	  else if(fram==1)
	  {
		  switch(letter){
			  case'A':
			  
			  myPORTC=0b01110010;
			  myPORTD=0b01010101;
			  mydelay10ms(30);
			  myPORTC=myPORTD=0x00;
			  mydelay10ms(30);
			  break;
			  
			  case'B':
			  
			  myPORTC=0b01100110;
			  myPORTD=0b00000110;
			  mydelay10ms(30);
			  myPORTC=myPORTD=0x00;
			  mydelay10ms(30);
			  break;
			  
			  case'C':
			  
			  
			  myPORTC=0b01000011;
			  myPORTD=0b01110100;
			  mydelay10ms(30);
			  myPORTC=myPORTD=0x00;
			  mydelay10ms(30);
			  break;
			  
			  
			  case'D':
			  
			  myPORTC=0b10100110;
			  myPORTD=0b01101010;
			  mydelay10ms(30);
			  myPORTC=myPORTD=0x00;
			  mydelay10ms(30);
			  break;
			  
			  
			  case'E':
			  
			  myPORTC=0b01110111;
			  myPORTD=0b00000111;
			  mydelay10ms(30);
			  myPORTC=myPORTD=0x00;
			  mydelay10ms(30);
			  break;
			  
			  default:
			  myPORTC=myPORTD=0xff;
			  break;
		  }
	  }
	  else
	  {
		  myPORTA=myPORTB=myPORTC=myPORTD=0xff;
		  mydelay10ms(30);
		  myPORTA=myPORTB=myPORTC=myPORTD=0x00;
	  }
  }
  
  

  
  
  