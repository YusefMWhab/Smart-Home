/*
 * LCD_Program.c
 *
 *  Created on: Apr 29, 2023
 *      Author: dell
 */
#include "..\include\LIB\BIT_MATH.h"
#include "..\include\LIB\STD_TYPES.h"

#include "..\include\MCAL\DIO\DIO_Interface.h"

#include "..\include\HAL\LCD\LCD_Interface.h"
#include "..\include\HAL\LCD\LCD_Private.h"
#include "..\include\HAL\LCD\LCD_cfg.h"

#include <util/delay.h>

#define F_CPU 8000000UL


// Sending Command to LCD

void HLCD_voidSendCommand(u8 A_u8Command)
	{
		// RS-->0 , RW-->0
		MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, PIN_RESET);
		MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, PIN_RESET);

		// Sending the Command
		MDIO_voidSetPortValue(LCD_DATA_PORT,A_u8Command);

		// Applying the E-Pulse
		MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,PIN_SET);
		_delay_ms(2);
		MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,PIN_RESET);
	}

// Sending Data to LCD

	void HLCD_voidSendData(u8 A_u8Data)
		{
			// RS-->1 , RW-->0
			MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, PIN_SET);
			MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, PIN_RESET);

			// Sending the Data
			MDIO_voidSetPortValue(LCD_DATA_PORT,A_u8Data);

			// Applying the E-Pulse
			MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,PIN_SET);
			_delay_ms(2);
			MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,PIN_RESET);
		}


// Initialization of LCD
	void HLCD_voidInit (void)
	{
		// Wait for more than 30 ms
		_delay_ms(30);

		// Function Set
		HLCD_voidSendCommand(FUNCTION_SET);

		// Wait for more than 39 us
		_delay_ms(1);

		// Display On/Off Control
		HLCD_voidSendCommand(DISPLAY_ON_OFF);

		// Wait for more than 39 us
		_delay_ms(1);

		// Clear Display
		HLCD_voidSendCommand(DISPLAY_CLEAR);

		// Wait for more than 1.53 ms
		_delay_ms(2);

		// ENTRY MODE SET
		HLCD_voidSendCommand(ENTRY_MODE_SET);

		// Wait for more than 39 us
		_delay_ms(1);

	}

	void HLCD_voidSendString(u8 *A_u8PtrToString)
		{
			while(*A_u8PtrToString>0)
			{
				HLCD_voidSendData(*A_u8PtrToString++);
			}
		}


	void HLCD_voidClearDisplay ()
	{
		// Clear Display
		HLCD_voidSendCommand(DISPLAY_CLEAR);
		// Wait for more than 1.53 ms
		_delay_ms(2);
	}

	void HLCD_voidGoToPos (LCD_ROWS A_ROW_NO, LCD_COLS A_COL_NO)
	{
		switch(A_ROW_NO)
		{
		case ROW1: HLCD_voidSendCommand(ROW1_ADDRESS + A_COL_NO); break;
		case ROW2: HLCD_voidSendCommand(ROW2_ADDRESS + A_COL_NO); break;
		}
	}
	void HLCD_voidDisplayNumber (u64 A_u32Number) // x
	{
		u64 local_u32Number=1; // y
		if ( A_u32Number == 0)
		{
			HLCD_voidSendData('0');
		}
		else
		{
			while(A_u32Number != 0)
			{
				local_u32Number = ((local_u32Number * 10) + (A_u32Number % 10));
				A_u32Number/=10;
			}
			while(local_u32Number != 1)
			{
				HLCD_voidSendData (((local_u32Number % 10) + 48));
				local_u32Number /=10;

			}
		}


	}

	void HLCD_voidSendSpescialPattern (u8 *A_pu8PatternArr, u8 A_PatternNo,LCD_ROWS A_RowNo, LCD_COLS A_ColNo)
	{
		u8 local_u8CGRamAddress;
		// Command 01ByteAddress
		local_u8CGRamAddress = A_PatternNo * 8;
		SET_BIT (local_u8CGRamAddress,6);
		// Send CGRAM Write Command
		HLCD_voidSendCommand(local_u8CGRamAddress);

		for (u8 i =0; i<8; i++)
		{
			// Send Custom Pattern to the LCD CGRAM
			HLCD_voidSendData(A_pu8PatternArr[i]);
		}

		// Send Position to DDRAM
		HLCD_voidGoToPos(A_RowNo, A_ColNo);
		// Display Pattern
		HLCD_voidSendData (A_PatternNo);
	}



