/*
 * atmega32_IO.h
 *
 * Created: 9/17/2016 10:33:34 AM
 *  Author: AhmedShaarawy
 */ 


#ifndef ATMEGA32_IO_H_
#define ATMEGA32_IO_H_

#include "atmega32_lib.h"

/*===================
** PORT DIRECTION.	=
===================*/

/********************************************************************************************************************
** =>> FUNCTION (1) FEATURES:																						*
** This function takes port_base and direction, then set the whole port with the input direction( INPUT or OUTPUT )	*
** It returns number of pins of the port if it succeeded otherwise it returns false.								*
** When it returns false it means that there is a false argument.													*
********************************************************************************************************************/
U8 IO_PortDir(U8 portBase, U8 dir);

/****************************************************************************
** =>> FUNCTION (2) FEATURES:												*
** This function takes a port_base, pin_number and a desired direction, 	*
** It sets that specific pin by the desired direction.						*
** It returns true if it succeeded otherwise it returns false.				*
** When it returns false it means that there is a false argument.			*
****************************************************************************/
U8 IO_PinDir(U8 portBase, U8 pin, U8 dir);

/********************************************************************************************************
** =>> FUNCTION (3) FEATURES:																			*
** This function takes a port_base, a pin range from first pin to second pin and a desired direction	*
** It sets the desired range by the desired direction.													*
** It returns number of pins in the range if it succeeded otherwise it returns false					*
** When it returns false it means that there is a false argument.										*
********************************************************************************************************/
U8 IO_PortRangeDir(U8 portBase, U8 firstPin, U8 lastPin, U8 dir);

/********************************************************************************************************
** =>> FUNCTION (4) FEATURES:																			*
** This function takes a port_base, a value indicates to selected pins and neglected pins on the port,	*
** and a value indicates the direction of each selected pin from the first value.						*
** and a second value indicates the direction of each selected pin from the first value.				*
** It neglects the zero pins in the first value even it obtained  ones in second value.					*
** It returns the number of selected or managed(out/in) pins if it succeeded otherwise it returns false.*
** When it returns false it means that there is a false argument.										*
********************************************************************************************************/
U8 IO_PortDirManage(U8 portBase, U8 binary_1sel_0neg, U8 binaryDir_1out_0in);




/*===================
** WRITING ON PORT.	=
===================*/

/****************************************************************************************************
** =>> FUNCTION (5) FEATURES:																		*
** This function takes a port_base, a value of one or zero, then write this value in the whole port.*
** It returns number of pins of the port if it succeeded otherwise it returns false.				*
** When it returns false it means that there is a false argument.									*
****************************************************************************************************/
U8 IO_PortWrite(U8 portBase, U8 val );

/************************************************************************************************
** =>> FUNCTION (6) FEATURES:																	*
** This function takes a port_base, a pin_number, a value of zero or one to write in the port	*
** It returns true if it succeeded otherwise it returns false.									*
** When it returns false it means that there is a false argument.								*
************************************************************************************************/
U8 IO_PinWrite(U8 portBase, U8 pin, U8 val);

/********************************************************************************************************************
** =>> FUNCTION (7) FEATURES:																						*
** This function takes a port_base, a range of a first pin and last pin and takes a value to write on this range.	*
** It returns number of pins in the range if it succeeded otherwise it returns false								*
** When it returns false it means that there is a false argument.													*
********************************************************************************************************************/
U8 IO_PortRangeWrite(U8 portBase, U8 firstPin, U8 lastPin, U8 val);

/********************************************************************************************************
** =>> FUNCTION (8) FEATURES:																			*
** This function takes a port_base, a value indicates to selected pins and neglected pins on the port,	*
** and a value indicates the values(zeros or ones) of each selected pin from the first value.			*
** and a second value indicates the value(zeros or ones) of each selected pin from the first value.		*
** It neglects the zero pins in the first value even it obtained  ones in second value.					*
** It returns the number of selected or managed pins if it succeeded otherwise it returns false.		*
** When it returns false it means that there is a false argument.										*
********************************************************************************************************/
U8 IO_PortWriteManage(U8 portBase, U8 binary_1sel_0neg, U8 binary_val);



/*=======================
** READING FROM PORT.	=
=======================*/

/****************************************************************************************************
** =>> FUNCTION (9) FEATURES:																		*
** This function takes a port_base, a reference to keep a read value of the port.					*
** It returns number of pins of the port if it succeeded otherwise it returns false.				*
** When it returns false it means that there is a false argument.									*
****************************************************************************************************/
U8 IO_PortRead(U8 portBase, U8 *portVal );

/************************************************************************************************
** =>> FUNCTION (10) FEATURES:																	*
** This function takes a port_base, a reference to keep a read value of the pin.				*
** It returns true if it succeeded otherwise it returns false.									*
** When it returns false it means that there is a false argument.								*
************************************************************************************************/
U8 IO_PinRead(U8 portBase, U8 pin, U8 *pinReadVal);

/****************************************************************************************************************************
** =>> FUNCTION (11) FEATURES:																								*
** This function takes a port_base, a range of a first pin and last pin and a reference to keep a read value of the range	*
** It returns number of pins in the range if it succeeded otherwise it returns false										*
** When it returns false it means that there is a false argument.															*
****************************************************************************************************************************/
U8 IO_PortRangeRead(U8 portBase, U8 firstPin, U8 lastPin, U8 *rangeReadVal);

/********************************************************************************************************
** =>> FUNCTION (12) FEATURES:																			*
** This function takes a port_base, a value indicates to selected pins and neglected pins on the port,	*
** and a reference to keep a read individual(zeros and ones) values of selected pins					*
** It neglects the zero pins in the first value even it obtained  ones in second value.					*
** It returns the number of selected or managed pins if it succeeded otherwise it returns false.		*
** When it returns false it means that there is a false argument.										*
********************************************************************************************************/
U8 IO_PortReadManage(U8 portBase, U8 binary_1sel_0neg, U8 *binaryIndividuals_readVal);




/*===============
** TOGGLING.	=
===============*/

/********************************************************************
** =>> FUNCTION (13) FEATURES:										*
**  This function toggles the whole port.							*
** It returns number of pins of the port otherwise it returns false	*
** When it returns false it means that there is a false argument.	*
********************************************************************/
U8 IO_PortToggle(U8 portBase);
/****************************************************************
** =>> FUNCTION (14) FEATURES:									*
** This function toggles the desired pin.						*
** It returns true if it succeeded otherwise it returns false	*
** When it returns false it means that there is a false argument*
****************************************************************/
U8 IO_PinToggle(U8 portBase, U8 pin);
/****************************************************************************************
** =>> FUNCTION (15) FEATURES:															*
** This function toggles range of pins from first to last pin.							*
** It returns number of pins in the range if it succeeded otherwise it returns false.	*
** When it returns false it means that there is a false argument.						*
****************************************************************************************/
U8 IO_PortRangeToggle(U8 portBase, U8 firstPin, U8 lastPin);
/********************************************************************************************
** =>> FUNCTION (16) FEATURES:																*
** This function takes a value represents the selected pins to toggle.						*
** It returns the number of selected pins if it succeeded otherwise it returns false.		*
** When it returns false it means that there is a false argument.							*
********************************************************************************************/
U8 IO_PortToggleManage(U8 portBase, U8 binary_1sel_0neg);


#endif /* ATMEGA32_IO_H_ */