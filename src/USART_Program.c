/*
 * USART_Program.c
 *
 *  Created on: Aug 1, 2023
 *      Author: dell
 */

#include "..\include\LIB\BIT_MATH.h"
#include "..\include\LIB\STD_TYPES.h"

#include "..\include\MCAL\USART\USART_Interface.h"
#include "..\include\MCAL\USART\USART_Private.h"
#include "..\include\MCAL\USART\USART_cfg.h"

#define F_CPU 8000000UL

void(*USART_Rx_Complete_Callback) (void)= NULL;
void(*USART_Tx_Complete_Callback) (void)= NULL;
void(*USART_UDR_Empty_Callback) (void)= NULL;

void MUSART_voidInit(void)
{
	//Baud Rate
	u16 Local_u16UBRRValue = BaudRateValue;
	UBRRL = (u8)Local_u16UBRRValue;
	UBRRH = (u8)(Local_u16UBRRValue >> 8);

	u8 Local_u8UCSRCValue = 0b10000000;

	//MultiProcessor Mode
	CLEAR_BIT(UCSRA,UCSRA_MPCM);
	UCSRA |= (USART_MultProcessorMode<<UCSRA_MPCM);

	// Double Speed
	CLEAR_BIT(UCSRA,UCSRA_U2X);
	UCSRA |= (USART_DoubleSPEED<<UCSRA_U2X);

	//Interrupts

	UCSRB &=0b00011111;
	UCSRB |=(USART_RXInterrupt<<UCSRB_RXCIE);
	UCSRB |=(USART_TXInterrupt<<UCSRB_TXCIE);
	UCSRB |=(USART_UDRInterrupt<<UCSRB_UDRIE);

	//Enable Rx & Tx
	SET_BIT(UCSRB,UCSRB_RXEN);
	SET_BIT(UCSRB,UCSRB_TXEN);

	//1-Byte-Sized Data
	CLEAR_BIT(UCSRB,UCSRB_UCSZ2);
	SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ1);

	//USART Mode
	Local_u8UCSRCValue |= (USART_MODE<<UCSRC_UMSEL);

	//Parity Mode
	Local_u8UCSRCValue |= (Parity_MODE<<4);

	//Stop Bits
	Local_u8UCSRCValue |= (USBS_MODE<<UCSRC_USBS);

	//Update UCSRC
	UCSRC = Local_u8UCSRCValue;

}

void MUSART_voidSendByte(u8 Copy_u8DataByte)
{
	//Wait Until Transmit Register is Empty
	while(GET_BIT(UCSRA,UCSRA_UDRE)==0);

	//Send Data Byte
	UDR = Copy_u8DataByte;
}

u8   MUSART_u8ReceiveByte()
{

		u8  Copy_Pu8DataByte ;
		//wait till there is a message
		while(GET_BIT(UCSRA,UCSRA_RXC)==0);
		Copy_Pu8DataByte = UDR;
		return Copy_Pu8DataByte;

}

void MUSART_u8ReceiveString(u8  Copy_Pu8DataString[])
{
	u8 i =0;

	Copy_Pu8DataString[i] = MUSART_u8ReceiveByte();

	while( (Copy_Pu8DataString[i] !='\r') && (Copy_Pu8DataString[i] !='\n') )
	{
		i++;
		Copy_Pu8DataString[i] = MUSART_u8ReceiveByte();
	}
	Copy_Pu8DataString[i]='\0';
}

void MUSART_voidSendString(u8 Copy_u8DataByte[])
{
	u8 i =0;
	while(Copy_u8DataByte[i] != '\0')
	{
		MUSART_voidSendByte(Copy_u8DataByte[i]);
		i++;
	}
}

void MUSART_voidClearUDR(void)
{
	u8 temp ;
	if(GET_BIT(UCSRA,UCSRA_RXC) == 1)
	{
		// CLEAR
		temp = UDR;

	}

}

//Set CallBack

void MUSART_voidRx_CompleteSetCallback(void(*ptrToFunc)(void))
{
	if  (ptrToFunc != NULL)
	{
			USART_Rx_Complete_Callback = ptrToFunc;
	}
}

void MUSART_voidTx_CompleteSetCallback(void(*ptrToFunc)(void))
{
	if  (ptrToFunc != NULL)
	{
		USART_Tx_Complete_Callback = ptrToFunc;
	}
}

void MUSART_voidUDR_EmptySetCallback(void(*ptrToFunc)(void))
{
	if  (ptrToFunc != NULL)
	{
		USART_UDR_Empty_Callback = ptrToFunc;
	}
}


void __vector_13 (void) __attribute__((signal));
void __vector_13 (void)
{
	if(USART_Rx_Complete_Callback != NULL)
	{
		USART_Rx_Complete_Callback();
	}
}

void __vector_15 (void) __attribute__((signal));
void __vector_15 (void)
{
	if(USART_Tx_Complete_Callback != NULL)
	{
		USART_Tx_Complete_Callback();
	}
}

void __vector_14 (void) __attribute__((signal));
void __vector_14 (void)
{
	if(USART_UDR_Empty_Callback != NULL)
	{
		USART_UDR_Empty_Callback();
	}
}


