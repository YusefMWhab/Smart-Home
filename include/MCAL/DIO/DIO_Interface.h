/*
 * DIO_Interface.h
 *
 *  Created on: Apr 28, 2023
 *      Author: dell
 */

#ifndef INCLUDE_MCAL_DIO_DIO_INTERFACE_H_
#define INCLUDE_MCAL_DIO_DIO_INTERFACE_H_

typedef enum
{
	PIN0=0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
}PIN_NO;

typedef enum
{
	PORTA=0,
	PORTB,
	PORTC,
	PORTD,
}PORT_NO;

typedef enum
{
	PIN_INPUT=0,
	PIN_OUTPUT
}PIN_DIRECTION;
typedef enum
{
	PIN_RESET=0,
	PIN_SET,
	PIN_FLOATING=0,
	PIN_PULLUP,
}PIN_VALUE;

//Prototypes
void MDIO_voidInit();
void MDIO_voidSetPinDirection(PORT_NO A_PORT_NO,PIN_NO A_PIN_NO,PIN_DIRECTION A_PIN_DIRECTION );
void MDIO_voidSetPinValue(PORT_NO A_PORT_NO,PIN_NO A_PIN_NO,PIN_VALUE A_PIN_VALUE );
void MDIO_voidSetPortValue(PORT_NO A_PORT_NO, u8 A_u8Value);
void MDIO_voidTogglePin(PORT_NO A_PORT_NO,PIN_NO A_PIN_NO);
u8 MDIO_voidGetPinValue(PORT_NO A_PORT_NO,PIN_NO A_PIN_NO);

#endif /* INCLUDE_MCAL_DIO_DIO_INTERFACE_H_ */
