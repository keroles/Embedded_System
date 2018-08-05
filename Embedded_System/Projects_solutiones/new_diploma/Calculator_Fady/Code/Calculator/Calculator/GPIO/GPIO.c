/*
 * GPIO.c
 *
 *  Created on: Aug 4, 2017
 *    *      Author: Keroles Shenouda
 *      https://www.facebook.com/groups/embedded.system.KS/
 */

#include "GPIO.h"



 volatile unsigned char*  GPIO_ports[] = {myPORTA,myPORTB,myPORTC,myPORTD};
 volatile unsigned char*  GPIO_dirs[] = {myDDRA,myDDRB,myDDRC,myDDRD};
 volatile unsigned char*  GPIO_pins[] = {myPINA,myPINB,myPINC,myPIND};

u8 get_port_index (u8 port_name)
{
	u8 i ;
	switch (port_name)
	{
	case 'A':
	case 'a':
		i = 0 ;
		break;
	case 'B' :
	case 'b':
		i = 1 ;
		break;
	case 'C':
	case 'c':
		i = 2 ;
		break;
	case 'D':
	case 'd':

		i = 3 ;
		break;

	}
return i ;

}



 void GPIO_voidInit(void)
{
	/*Comment!: DDR initialization  */
	*GPIO_dirs[0] = Init_direction_default;
	*GPIO_dirs[1] = Init_direction_default;
	*GPIO_dirs[2] = Init_direction_default;
	*GPIO_dirs[3] = Init_direction_default;

}

//===================PIN==========================
//Data
/*Comment!: Read Pin Value */
u8 GPIO_u8_ReadPinVal(u8 PinIdx,u8* PtrToVal, u8 Port_Name)
{
	u8 API_Status ;

	if(PinIdx > no_of_pins_on_port - 1)
	{
		API_Status = error_happen;
	}
	else
	{

		*PtrToVal =  ((*GPIO_pins [ get_port_index(Port_Name) ] >>PinIdx)&1) ;
		API_Status = No_error;
	}

	return API_Status ;

}

/*Comment!: Write Pin Value */
u8 GPIO_u8_WritePinVal(u8 PinIdx,u8 PinVal , u8 Port_Name)
{
	u8 API_Status ;

	if(PinIdx > no_of_pins_on_port - 1)
	{
		API_Status = error_happen;
	}
	else
	{
		switch(PinVal)
		{
		case 1:
			*GPIO_ports[ get_port_index(Port_Name) ] |= 1<<PinIdx;
			API_Status = No_error;
			break;
		case 0:
			*GPIO_ports[ get_port_index(Port_Name) ] &= ~(1<<PinIdx) ;
			API_Status = No_error;
			break;
		default:
			API_Status = error_happen;
			break;

		}
	}

	return API_Status ;

}

//Direction
/*Comment!: Write Pin Direction */
u8 GPIO_u8_WritePinDir(u8 PinIdx,u8 PinDir , u8 Port_Name)
{
	u8 API_Status ;

	if(PinIdx > no_of_pins_on_port - 1)
	{
		API_Status = error_happen;
	}
	else
	{
		switch(PinDir)
		{
		case 1:
			*GPIO_dirs[ get_port_index(Port_Name) ] |= 1<<PinIdx;
			API_Status = No_error;
			break;
		case 0:
			*GPIO_dirs[ get_port_index(Port_Name) ] &= ~(1<<PinIdx) ;
			API_Status = No_error;
			break;
		default:
			API_Status = error_happen;
			break;

		}
	}

	return API_Status ;

}

/*Comment!: Read Pin Direction */
u8 GPIO_u8_ReadPinDir(u8 PinIdx,u8* PtrToDir , u8 Port_Name )
{

	u8 API_Status ;

	if(PinIdx > no_of_pins_on_port - 1)
	{
		API_Status = error_happen;
	}
	else
	{
		*PtrToDir =  ((*GPIO_dirs [ get_port_index(Port_Name) ] >> PinIdx) & 1) ;
		API_Status = No_error;
	}

	return API_Status ;


}
/////////////////////////////////////////////////
//===================PORT==========================
//Data
/*Comment!: Read Port Value */
u8 GPIO_u8_ReadPortVal(u8* PtrToVal , u8 Port_Name)
{

	*PtrToVal =  *GPIO_pins [ get_port_index(Port_Name) ] ;

	return No_error ;

}

/*Comment!: Write Port Value */
u8 GPIO_u8_WritePortVal(u8 PortVal , u8 Port_Name)
{
	*GPIO_ports[ get_port_index(Port_Name) ] = PortVal ;
	return No_error ;


}

//Direction
/*Comment!: Write Port Direction */
u8 GPIO_u8_WritePortDir(u8 PortDir, u8 Port_Name)
{
	  *GPIO_dirs [ get_port_index(Port_Name) ] = PortDir;

	return No_error ;

}

/*Comment!: Read Port Direction */
u8 GPIO_u8_ReadPortDir(u8* PtrToDir, u8 Port_Name)
{
	*PtrToDir =  *GPIO_dirs[ get_port_index(Port_Name) ] ;

	return No_error ;


}
//====================================================================
