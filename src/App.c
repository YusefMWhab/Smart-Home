/*
 * App.c
 *
 *  Created on: Sep 23, 2023
 *      Author: dell
 */
#include <util/delay.h>

#include "..\include\LIB\BIT_MATH.h"
#include "..\include\LIB\STD_TYPES.h"

#include "..\include\MCAL\DIO\DIO_Interface.h"
#include "..\include\MCAL\GI\GI_Interface.h"
#include "..\include\MCAL\Timers\Timers_Interface.h"
#include "..\include\MCAL\USART\USART_Interface.h"
#include "..\include\HAL\LCD\LCD_Interface.h"
#include"Configuration.h"

#include "string.h"


//Create Users
USERS GlobalArrOfUsers[MaxUsers];
u8 GlobalReceivedData[MaxDataReceivedLen];

void USERS_voidInit(void);
void Alarm_voidOn(void);
void TIMER2_ISR(void);
void ProgramFun (void);
void ActionFun (void);
s8 USERS_voidGetUsername (void);
s8 GetUserPassword(u8 temp);
s8 SearchForUsername(u8 Target []);


int main()
{
	//Initialization :
	MDIO_voidInit();
	MGI_voidEnable();
	MTIMER2_voidSetCTCCallback(TIMER2_ISR);
	HLCD_voidInit();
	MUSART_voidInit();
	USERS_voidInit();

	while(1)
	{
		ProgramFun();
	}
}



void USERS_voidInit(void)
{
	for(u8 i = 0; i < MaxUsers; i++ )
	{
		strcpy(GlobalArrOfUsers[i].Username,ArrOfUsername[i]);
		strcpy(GlobalArrOfUsers[i].Password,ArrOfPassword[i]);
	}
}

//Main Function in Program that Handle all Tasks (other functions)
void ProgramFun (void)
{
	s8 Local_s8UsernameFlag = -1;
	s8 Local_s8PasswordFlag = -1;
	s8 Local_s8UserIndex    = -1;

	Local_s8UsernameFlag = USERS_voidGetUsername();
	Local_s8UserIndex = Local_s8UsernameFlag; //UserName Index


	if(Local_s8UsernameFlag != -1) 		// --> Username has been found
	{

		Local_s8PasswordFlag = GetUserPassword(Local_s8UserIndex);

		if (Local_s8PasswordFlag != -1)     // --> Password is Correct
		{
			ActionFun();
		}
	}
}

s8 USERS_voidGetUsername (void)
{
	u8 Local_u8AlarmCounter = 0;
	s8 Local_s8UsernameFoundCheck = -1 ;
	s8 Local_s8PasswordFoundCheck = -1 ;

	HLCD_voidClearDisplay();
	HLCD_voidSendString("Enter UserName!");
	MUSART_voidSendString("Enter UserName!\n");

	while( (Local_u8AlarmCounter < 3) && (Local_s8UsernameFoundCheck == -1) )
	{

		Local_u8AlarmCounter++;

		MUSART_voidClearUDR(); //CLEAR USART Receiving Buffer before reading it
		MUSART_u8ReceiveString(GlobalReceivedData);
		Local_s8UsernameFoundCheck = SearchForUsername(GlobalReceivedData);

		if (Local_s8UsernameFoundCheck == -1) // --> Not found
		{
			if (Local_u8AlarmCounter == 3)  // --> User has entered wrong Data for three times
			{
				HLCD_voidClearDisplay();
				HLCD_voidSendString("Warning!");
				MUSART_voidSendString("Warning!\n");
				Alarm_voidOn();
				_delay_ms(3000);

			}
			else
			{
			HLCD_voidClearDisplay();
			HLCD_voidSendString("Wrong Username!");
			HLCD_voidGoToPos(2,1);
			HLCD_voidSendString("Try Again!");
			MUSART_voidSendString("Wrong Username\nTry Again!");

			}
		}

		else
		{
			//User has entered a correct username
			HLCD_voidClearDisplay();
			HLCD_voidSendString("Welcome ");
			HLCD_voidSendString(GlobalArrOfUsers[Local_s8UsernameFoundCheck].Username);
			MUSART_voidSendString("Welcome\n");
		}
	}
	return Local_s8UsernameFoundCheck;
}


s8 SearchForUsername(u8 Target [])
{
	s8 temp = -1;
	for(u8 i = 0 ; i < MaxUsers ; i++)
	{
		if (strcmp(Target , GlobalArrOfUsers[i].Username) == 0 )
		{
			temp = i;
			break;
		}

	}
	return temp; // -1 --> not found
				// else--> index

}

//Function to Get Password From Users
s8 GetUserPassword(u8 temp)
{
	u8 Local_u8AlarmCounter = 0;
	s8 Local_s8PasswordFoundCheck = -1 ;

	HLCD_voidGoToPos(2,1);
	HLCD_voidSendString("Enter Password");
	MUSART_voidSendString("Enter Password\n");


	while( (Local_u8AlarmCounter < 3) && (Local_s8PasswordFoundCheck == -1) )
	{
		Local_u8AlarmCounter++;
		MUSART_u8ReceiveString(GlobalReceivedData);  // Get Data From User
		if (strcmp(GlobalReceivedData ,GlobalArrOfUsers[temp].Password) == 0)   // Password is correct
		{
			Local_s8PasswordFoundCheck = 1;
		}
		else
		{
			if (Local_u8AlarmCounter == 3)
			{
				HLCD_voidClearDisplay();
				HLCD_voidSendString("Warning!");
				MUSART_voidSendString("Warning!\n");
				Alarm_voidOn();
				_delay_ms(3000);
			}
			else
			{
				HLCD_voidClearDisplay();
				HLCD_voidSendString("Wrong Password!");
				HLCD_voidGoToPos(2,1);
				HLCD_voidSendString("Try Again!");
				MUSART_voidSendString("Wrong Password\nTry Again!");

			}
		}

	}

	return Local_s8PasswordFoundCheck;
}

// Function that ask Users to chose an action
void ActionFun (void)
{
	u8 Local_u8ReceivedData ;

	//Ask User to Enter an Action
	HLCD_voidClearDisplay();
	HLCD_voidSendString("Chose an Action!");
	MUSART_voidSendString("Chose an Action!\n");
	Local_u8ReceivedData = MUSART_u8ReceiveByte();

	while(Local_u8ReceivedData != LogOut)
	{
		switch (Local_u8ReceivedData)
		{

			case LedOn :
				//Open led
				HLCD_voidClearDisplay();
				HLCD_voidSendString("Led On");
				MUSART_voidSendString("Led On\n");
				MDIO_voidSetPinValue(PORTA,PIN4,PIN_SET);
				break;

			case LedOff :
				//Off led
				HLCD_voidClearDisplay();
				HLCD_voidSendString("Led Off");
				MUSART_voidSendString("Led Off\n");
				MDIO_voidSetPinValue(PORTA,PIN4,PIN_RESET);
				break;

			case DoorOpen :
				//Open Door
				HLCD_voidClearDisplay();
				HLCD_voidSendString("Door Open");
				MUSART_voidSendString("Door Open\n");
				MDIO_voidSetPinValue(PORTA,PIN2,PIN_SET);
				MDIO_voidSetPinValue(PORTA,PIN3,PIN_RESET);


				break;

			case DoorLocked :
				//Lock Door
				HLCD_voidClearDisplay();
				HLCD_voidSendString("Door Locked");
				MUSART_voidSendString("Door Open\n");
				MDIO_voidSetPinValue(PORTA,PIN2,PIN_RESET);
				MDIO_voidSetPinValue(PORTA,PIN3,PIN_SET);

				break;
		}

		Local_u8ReceivedData = MUSART_u8ReceiveByte();
	}
}

void TIMER2_ISR(void)
{
	static u16 Timer2_OnCounter = 0;
	static u16 Timer2_OffCounter = 0;
	Timer2_OffCounter++;
	Timer2_OnCounter++;
	if(Timer2_OnCounter == 1500)
	{
		Timer2_OnCounter = 0;
		MDIO_voidTogglePin(PORTA,PIN0);
		MDIO_voidTogglePin(PORTA,PIN1);
	}
	if(Timer2_OffCounter==15000)
	{
		Timer2_OffCounter=0;
		MTIMER2_voidStopTimer();
	}

}

void Alarm_voidOn(void)
{
	MTIMER2_voidInit();
}

