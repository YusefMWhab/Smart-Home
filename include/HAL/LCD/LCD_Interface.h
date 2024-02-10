/*
 * LCD_Interface.h
 *
 *  Created on: Apr 29, 2023
 *      Author: dell
 */

#ifndef INCLUDE_HAL_LCD_LCD_INTERFACE_H_
#define INCLUDE_HAL_LCD_LCD_INTERFACE_H_


typedef enum
{
	COL1=1,
	COL2,
	COL3,
	COL4,
	COL5,
	COL6,
	COL7,
	COL8,
	COL9,
	COL10,
	CLO11,
	COL12,
	COL13,
	COL14,
	COL15,
	COL16,
}LCD_COLS;

typedef enum
{
	ROW1=1,
	ROW2
}LCD_ROWS;

void HLCD_voidInit ();
void HLCD_voidSendCommand(u8 A_u8Command);
void HLCD_voidSendData(u8 A_u8Data);
void HLCD_voidClearDisplay ();
void HLCD_voidSendString (u8 *A_u8PtrToString);
void HLCD_voidGoToPos (LCD_ROWS A_ROW_NO, LCD_COLS A_COL_NO);
void HLCD_voidDisplayNumber (u64 A_u32Number);
void HLCD_voidSendSpescialPattern (u8 *A_pu8PatternArr, u8 A_PatternNo,LCD_ROWS A_RowNo, LCD_COLS A_ColNo);
#endif /* INCLUDE_HAL_LCD_LCD_INTERFACE_H_ */
