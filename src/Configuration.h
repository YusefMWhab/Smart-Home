/*
 * Configuration.h
 *
 *  Created on: Sep 23, 2023
 *      Author: dell
 */

#ifndef SRC_CONFIGURATION_H_
#define SRC_CONFIGURATION_H_


#define MaxUsernameLen      10
#define MaxPasswordLen      6
#define MaxDataReceivedLen  15 //Buffer to Recieve Data from Bluetooth
#define MaxUsers            10
#define MaxNoOfActions      4



/*______________________________________________________________*/

//Configuration of Data (Username , Password)

// User1
#define username1 "User1"
#define password1 "1234"
// User2
#define username2 "User2"
#define password2 "1234"
// User3
#define username3 "User3"
#define password3 "1234"
// User4
#define username4 "User4"
#define password4 "1234"
// User5
#define username5 "User5"
#define password5 "1234"
// User6
#define username6 "User6"
#define password6 "1234"
// User7
#define username7 "User7"
#define password7 "1234"
// User8
#define username8 "User8"
#define password8 "1234"
// User9
#define username9 "User9"
#define password9 "1234"
// User10
#define username10 "User10"
#define password10 "1234"

u8 ArrOfUsername[MaxUsers][MaxUsernameLen] =
{	{username1},{username2},{username3},{username4},{username5},{username6},{username7},{username8},{username9},{username10} };

u8 ArrOfPassword[MaxUsers] [MaxPasswordLen] =
{	{password1},{password2},{password3},{password4},{password5},{password6},{password7},{password8},{password9},{password10} };

/*__________________________________________________________________________*/

// Configuration of Actions

//Action0
#define LogOut       '0'
//Action1
#define LedOn        '1'
//Action2
#define  LedOff      '2'
//Action3
#define  DoorOpen    '3'
//Action4
#define  DoorLocked  '4'

/*________________________________________________________________________*/

typedef struct
{
	u8 Username[MaxUsernameLen];
	u8 Password[MaxPasswordLen];
}USERS;




#endif /* SRC_CONFIGURATION_H_ */
