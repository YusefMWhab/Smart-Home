/*
 * USART_Interface.h
 *
 *  Created on: Aug 1, 2023
 *      Author: dell
 */

#ifndef INCLUDE_MCAL_USART_USART_INTERFACE_H_
#define INCLUDE_MCAL_USART_USART_INTERFACE_H_


void MUSART_voidInit(void);
void MUSART_voidSendByte(u8 Copy_u8DataByte);
u8   MUSART_u8ReceiveByte();
void MUSART_u8ReceiveString(u8 Copy_Pu8DataByte[]);
void MUSART_voidSendString(u8 Copy_u8DataByte[]);
void MUSART_voidClearUDR(void);

void MUSART_voidRx_CompleteSetCallback(void(*ptrToFunc)(void));
void MUSART_voidTx_CompleteSetCallback(void(*ptrToFunc)(void));
void MUSART_voidUDR_EmptySetCallback(void(*ptrToFunc)(void));


#endif /* INCLUDE_MCAL_USART_USART_INTERFACE_H_ */
