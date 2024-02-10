/*
 * DIO_Program.c
 *
 *  Created on: Apr 28, 2023
 *      Author: dell
 */
#include "..\include\LIB\BIT_MATH.h"
#include "..\include\LIB\STD_TYPES.h"
#include "..\include\MCAL\DIO\DIO_Interface.h"
#include "..\include\MCAL\DIO\DIO_Private.h"
#include "..\include\MCAL\DIO\DIO_cfg.h"

void MDIO_voidInit()
{

DDRA_REG=CONC_BIT(PORTA_P7_DIRECTION,PORTA_P6_DIRECTION,PORTA_P5_DIRECTION,PORTA_P4_DIRECTION,PORTA_P3_DIRECTION,PORTA_P2_DIRECTION,PORTA_P1_DIRECTION,PORTA_P0_DIRECTION);
DDRB_REG=CONC_BIT(PORTB_P7_DIRECTION,PORTB_P6_DIRECTION,PORTB_P5_DIRECTION,PORTB_P4_DIRECTION,PORTB_P3_DIRECTION,PORTB_P2_DIRECTION,PORTB_P1_DIRECTION,PORTB_P0_DIRECTION);
DDRC_REG=CONC_BIT(PORTC_P7_DIRECTION,PORTC_P6_DIRECTION,PORTC_P5_DIRECTION,PORTC_P4_DIRECTION,PORTC_P3_DIRECTION,PORTC_P2_DIRECTION,PORTC_P1_DIRECTION,PORTC_P0_DIRECTION);
DDRD_REG=CONC_BIT(PORTD_P7_DIRECTION,PORTD_P6_DIRECTION,PORTD_P5_DIRECTION,PORTD_P4_DIRECTION,PORTD_P3_DIRECTION,PORTD_P2_DIRECTION,PORTD_P1_DIRECTION,PORTD_P0_DIRECTION);
/****************************************************/
PORTA_REG=CONC_BIT(PORTA_P7_VALUE,PORTA_P6_VALUE,PORTA_P5_VALUE,PORTA_P4_VALUE,PORTA_P3_VALUE,PORTA_P2_VALUE,PORTA_P1_VALUE,PORTA_P0_VALUE);
PORTB_REG=CONC_BIT(PORTB_P7_VALUE,PORTB_P6_VALUE,PORTB_P5_VALUE,PORTB_P4_VALUE,PORTB_P3_VALUE,PORTB_P2_VALUE,PORTB_P1_VALUE,PORTB_P0_VALUE);
PORTC_REG=CONC_BIT(PORTC_P7_VALUE,PORTC_P6_VALUE,PORTC_P5_VALUE,PORTC_P4_VALUE,PORTC_P3_VALUE,PORTC_P2_VALUE,PORTC_P1_VALUE,PORTC_P0_VALUE);
PORTD_REG=CONC_BIT(PORTD_P7_VALUE,PORTD_P6_VALUE,PORTD_P5_VALUE,PORTD_P4_VALUE,PORTD_P3_VALUE,PORTD_P2_VALUE,PORTD_P1_VALUE,PORTD_P0_VALUE);
}

/********************************************/

void MDIO_voidSetPinDirection( PORT_NO A_PORT_NO, PIN_NO A_PIN_NO,PIN_DIRECTION A_PIN_DIRECTION )
{

	//Input validation ?
	if((A_PORT_NO<=PORTD) && (A_PIN_NO<=PIN7) && (A_PIN_DIRECTION<=PIN_OUTPUT))
	{
	switch (A_PORT_NO)
	{
	case PORTA :
				switch (A_PIN_DIRECTION)
				{
				case PIN_INPUT :CLEAR_BIT(DDRA_REG,A_PIN_NO); break;
				case PIN_OUTPUT :SET_BIT(DDRA_REG,A_PIN_NO); break;
				}
				break;

	case PORTB :
				switch (A_PIN_DIRECTION)
				{
				case PIN_INPUT :CLEAR_BIT(DDRA_REG,A_PIN_NO); break;
				case PIN_OUTPUT :SET_BIT(DDRA_REG,A_PIN_NO); break;
				}
				break;

	case PORTC :
				switch (A_PIN_DIRECTION)
				{
				case PIN_INPUT :CLEAR_BIT(DDRA_REG,A_PIN_NO); break;
				case PIN_OUTPUT :SET_BIT(DDRA_REG,A_PIN_NO); break;
				}
				break;

	case PORTD :
				switch (A_PIN_DIRECTION)
				{
					case PIN_INPUT :CLEAR_BIT(DDRA_REG,A_PIN_NO); break;
					case PIN_OUTPUT :SET_BIT(DDRA_REG,A_PIN_NO); break;
				}
				break;
	}
	}
}
/*************************************************************************/
/*
To Set an Output Pin as High(1) Or Low(0)
To set an Input Pin as Floating(0) Or Pullup(1)
*/
void MDIO_voidSetPinValue(PORT_NO A_PORT_NO,PIN_NO A_PIN_NO,PIN_VALUE A_PIN_VALUE )
{

	//Input validation ?
	if((A_PORT_NO<=PORTD) && (A_PIN_NO<=PIN7) && (A_PIN_VALUE<=PIN_SET))
	{
	switch (A_PORT_NO)
	{
	case PORTA :
				switch (A_PIN_VALUE)
				{
				case PIN_RESET :CLEAR_BIT(PORTA_REG,A_PIN_NO); break;
				case PIN_SET :SET_BIT(PORTA_REG,A_PIN_NO); break;
				}
				break;

	case PORTB :
				switch (A_PIN_VALUE)
				{
				case PIN_RESET :CLEAR_BIT(PORTB_REG,A_PIN_NO); break;
				case PIN_SET :SET_BIT(PORTB_REG,A_PIN_NO); break;
				}
				break;

	case PORTC :
				switch (A_PIN_VALUE)
				{
				case PIN_RESET :CLEAR_BIT(PORTC_REG,A_PIN_NO); break;
				case PIN_SET :SET_BIT(PORTC_REG,A_PIN_NO); break;
				}
				break;

	case PORTD :
				switch (A_PIN_VALUE)
				{
					case PIN_RESET :CLEAR_BIT(PORTD_REG,A_PIN_NO); break;
					case PIN_SET :SET_BIT(PORTD_REG,A_PIN_NO); break;
				}
				break;
	}
	}
}
void MDIO_voidSetPortValue(PORT_NO A_PORT_NO, u8 A_u8Value)
{

	if(A_PORT_NO<=PORTD)
	{
		switch(A_PORT_NO)
		{
		case PORTA : PORTA_REG = A_u8Value; break;
		case PORTB : PORTB_REG = A_u8Value; break;
		case PORTC : PORTC_REG = A_u8Value; break;
		case PORTD : PORTD_REG = A_u8Value; break;
		}
	}
}

void MDIO_voidTogglePin(PORT_NO A_PORT_NO,PIN_NO A_PIN_NO)
{
	if((A_PORT_NO<=PORTD) && (A_PIN_NO<=PIN7))
	{
		switch (A_PORT_NO)
		{
		case PORTA : TOGGLE_BIT(PORTA_REG,A_PIN_NO); break;
		case PORTB : TOGGLE_BIT(PORTB_REG,A_PIN_NO); break;
		case PORTC : TOGGLE_BIT(PORTC_REG,A_PIN_NO); break;
		case PORTD : TOGGLE_BIT(PORTD_REG,A_PIN_NO); break;
		}
	}
}
u8 MDIO_voidGetPinValue(PORT_NO A_PORT_NO,PIN_NO A_PIN_NO)
{

	u8 PinValue=0;
	if((A_PORT_NO<=PORTD) && (A_PIN_NO<=PIN7))
		{

			switch (A_PORT_NO)
			{
			case PORTA : 	PinValue=GET_BIT(PINA_REG,A_PIN_NO); break;
			case PORTB :    PinValue=GET_BIT(PINB_REG,A_PIN_NO); break;
			case PORTC :    PinValue=GET_BIT(PINC_REG,A_PIN_NO); break;
			case PORTD :    PinValue=GET_BIT(PIND_REG,A_PIN_NO); break;
			}

		}
	return PinValue;

}




