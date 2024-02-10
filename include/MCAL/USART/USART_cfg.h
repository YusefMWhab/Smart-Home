/*
 * USART_cfg.h
 *
 *  Created on: Aug 1, 2023
 *      Author: dell
 */

#ifndef INCLUDE_MCAL_USART_USART_CFG_H_
#define INCLUDE_MCAL_USART_USART_CFG_H_

/*
 * Double Speed Options:
 * 		Disable (Normal speed)
 * 		Enable (Double Speed)
 */
#define USART_DoubleSPEED Disable

/*
 * MultiProcessor Mode options:
 * 		Disable
 * 		Enable
 */
#define USART_MultProcessorMode Disable

/*
 * Interrupts Options :
 * 		Disable
 * 		Enable
 */
//RX Complete Interrupt Enable
#define USART_RXInterrupt Disable
//TX Complete Interrupt Enable
#define USART_TXInterrupt Disable
//Data Register Empty Interrupt Enable
#define USART_UDRInterrupt Disable

/*
 *USART MODE Options:
 *		Asynchronous_Operation
 *		Synchronous_Operation
 */
#define USART_MODE Asynchronous_Operation

/*
 * Parity Mode Options:
 * 		Parity_Disable
 * 		Parity_Even
 * 		Parity_Odd
 */
#define Parity_MODE Parity_Disable

/*
 * USBS Bit Options:
 * 		USBS1 (1-bit)
 * 		USBS2 (2-bit)
 */
#define USBS_MODE USBS1

//Baud Rate Value
#define BaudRateValue 51


#endif /* INCLUDE_MCAL_USART_USART_CFG_H_ */
