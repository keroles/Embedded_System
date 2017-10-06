/*
 * SPI.c
 *
 *  Created on: Oct 6, 2017
 *      Author: kkhalil
 */
#include "SPI.h"
#include "avr/io.h"
#include "avr/interrupt.h"

struct S_SPI_Configuration gConfig ;

static void (*SPI_ISR)(void);

void SPI_voidInit(struct S_SPI_Configuration spi_Config )
{

	gConfig = spi_Config ;
		/********************Enable SPI Interrupt ******************/
	//SPCR = SPCR | (SPI_INT_ENABLE<<SPIE);
	//SPCR = SPCR |  (SPI_INT_ENABLE<<SPIE) | (SPI_ENABLE<<SPE) | (SPI_DATA_ORDER<<DORD) | (SLAVE_MODE<<MSTR) | (SPI_OPERATING_LEVEL<<CPOL) | (SPI_SAMPLING_EDGE<<CPHA) | (SPI_PRESCALAR);


	if (gConfig.INT_ENABLE == SPI_INT_ON)
		SetBit(SPCR,SPIE);
	else if (gConfig.INT_ENABLE == SPI_INT_OFF)
		ClrBit(SPCR,SPIE);

	/*******************Data Order ******************/

	if (gConfig.DATA_ORDER == SPI_LSB_FISRT)
		SetBit(SPCR,DORD);
	else if (gConfig.DATA_ORDER == SPI_MSB_FISRT)
		ClrBit(SPCR,DORD);

	/********************Master Slave Select ******************/

	if (gConfig.SLAVE_MODE == SPI_MASTER)
		SetBit(SPCR,MSTR);
	else if (gConfig.SLAVE_MODE == SPI_SLAVE)
		ClrBit(SPCR,MSTR);

	/********************clock polarity******************/
	if (gConfig.OPERATING_LEVEL == SPI_IDLE_LOW)
		SetBit(SPCR,CPOL);
	else if (gConfig.OPERATING_LEVEL == SPI_IDLE_HIGH)
		ClrBit(SPCR,CPOL);

	/********************clock phase******************/
	if (gConfig.SAMPLING_EDGE == SPI_RISING)
		SetBit(SPCR,CPHA);
	else if (gConfig.SAMPLING_EDGE == SPI_FALLING)
		ClrBit(SPCR,CPHA);

	/********************SPI pre-scalar in case of master ******************/
		SPCR = SPCR | (gConfig.PRESCALAR);
	/********************Double SPI speed if master******************/

		if (gConfig.DOUBLE_SPEED == SPI_DOUBLE_SPEED_MODE_ON)
			SetBit(SPSR,SPI2X);
		else if (gConfig.DOUBLE_SPEED == SPI_DOUBLE_SPEED_MODE_OFF)
			ClrBit(SPSR,SPI2X);

	/********************Enable SPI ******************/
		if (gConfig.ENABLE == SPI_ENABLE_ON)
			SetBit(SPCR,SPE);
			else if (gConfig.ENABLE == SPI_ENABLE_OFF)
				ClrBit(SPCR,SPE);

}



u8  SPI_Send_And_receive(u8 Copy_u8Data)
{
	SPDR = Copy_u8Data; //send data
	while(!(SPSR & (1<<SPIF)));
	return SPDR ; // Received data

}

 u8 SPI_Checks_for_collision(void)
{
	u8 local_u8CollStatus = GetBit(SPSR,WCOL);
	return local_u8CollStatus;
}


  void SPI_callBackFunc_Assign(void (*PtrToSPI_Isr) (void))
 {
 	SPI_ISR = PtrToSPI_Isr;
 }


  ISR(SPI_STC_vect)
  {
  	SPI_ISR();
  }

