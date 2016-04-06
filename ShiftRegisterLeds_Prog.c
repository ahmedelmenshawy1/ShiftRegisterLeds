/*
 * ShiftRegisterLeds_Prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */
#include "Types.h"
#include "DIO_interface.h"
#include "ShiftRegisterLeds_Config.h"
#include "ShiftRegisterLeds_Interface.h"
#include "DIO-utilites.h"
#include "delay.h"
/***********************************************/
void Down_Slow(void)
{
		 /*
		 shift_int(1,SRL_u8Pin);
		 shift_int(1,SRL_u8Pin);
		 shift_int(1,SRL_u8Pin);
		 shift_int(1,SRL_u8Pin);
		 shift_int(0,SRL_u8Pin);
		 shift_int(0,SRL_u8Pin);
		 shift_int(0,SRL_u8Pin);
		 */
		 shift_int(0x2c,SRL_u8Port);
}
/***********************************************/

int main (void)
{
	DIO_VoidInit();
	Down_Slow();
	while(1);
	return 0;
}
/******************************************/
extern u8 shift_int(u8 Copy_u8Val,u8 Copy_u8PinOrPort)
{
	s8 	Local_u8Status;
	if(Copy_u8PinOrPort==SRL_u8Pin )
	{
		static u8 SRL_u8StaticLocalCounter;

		DIO_u8WritePinVal(SRL_u8Clk,DIO_u8LOW );
		SRL_u8StaticLocalCounter++;
		DIO_u8WritePinVal(SRL_u8DATA,Copy_u8Val );
		DIO_u8WritePinVal(SRL_u8Clk,DIO_u8HIGH );
		if(SRL_u8StaticLocalCounter==8)
		{
			DIO_u8WritePinVal(SRL_u8Latch,DIO_u8HIGH );
			DIO_u8WritePinVal(SRL_u8Latch,DIO_u8LOW );
			SRL_u8StaticLocalCounter=DIO_u8LOW;
		}
		else{}
		Local_u8Status=Ok;
	}
	else if(Copy_u8PinOrPort==SRL_u8Port)//shrt 3shan dh hwa hib3t yklm port bs
	{
		for(Local_u8Status=7;Local_u8Status>=0;Local_u8Status--)
		{
			DIO_u8WritePinVal(SRL_u8Clk,DIO_u8LOW );
			DIO_u8WritePinVal(SRL_u8DATA,Get_Bit(Copy_u8Val,Local_u8Status));
			DIO_u8WritePinVal(SRL_u8Clk,DIO_u8HIGH );
		}
		DIO_u8WritePinVal(SRL_u8Latch,DIO_u8HIGH );
		DIO_u8WritePinVal(SRL_u8Latch,DIO_u8LOW );
		Local_u8Status=Ok;
	}
	else
	{
		Local_u8Status=Error;
	}
	return Local_u8Status;
}
