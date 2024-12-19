/*
 * password.c
 *
 *  Created on: Nov 12, 2024
 *      Author: ACER
 */

//--- Private Include ----------------------------

#include "password.h"

//--- Variables ----------------------------------
//- Local Variables ------------------------------
static uint8_t 	password_typed_index;
char 			password_typed_chars[PASSWORD_LENGTH];
char			PASSWORD[] = "170404";

//- Global Variables -----------------------------
uint8_t flag_password_correct;

//--- Functions Definition -----------------------
//- Local Functions ------------------------------

/*	Function: compare(void)
 * 	Return: none
 * 	Purpose: compare two string to check whether it is similar or not;
 */
uint8_t compare(void)
{
	if(password_typed_index != PASSWORD_LENGTH)
		return 0;
	for(uint8_t i = 0; i<PASSWORD_LENGTH; ++i)
	{
		if(password_typed_chars[i] != PASSWORD[i]){
			return 0;
		}
	}
	return 1;
}

//- Global Functions -----------------------------
/*	Function: password_reset(void)
 * 	Return: none
 * 	Purpose: reset password to default state
 */
void password_reset(void){
	flag_password_correct = PASSWORD_FLOATING;
	password_typed_index  = 0;
	for(uint8_t i = 0; i<PASSWORD_LENGTH; ++i){
		password_typed_chars[i] = '\0';
	}
}

/* 	Function: password_run()
 * 	Return: non
 * 	Purpose: run continuosly until an event occurs
 */
void password_run(char c){
	switch(c){
		case '\0':
			break;
		case 'e':
			if(password_typed_index == 0){
				break;
			}
			if(!compare()){
				flag_password_correct = PASSWORD_WRONG;
				break;
			}
			flag_password_correct = PASSWORD_CORRECT;
			break;
		case 'd':
			password_reset();
			break;
		default:
			if(password_typed_index == PASSWORD_LENGTH)
				break;
			password_typed_chars[password_typed_index] = c;
			++password_typed_index;
			if(password_typed_index >= 6){
				password_typed_chars[password_typed_index] = '\0';
			}
			break;
	}
}

/* 	Function: password_get_typed_index()
 * 	Return: non
 * 	Purpose: Return cursor position
 */
uint8_t password_get_typed_index(void){
	return password_typed_index;
}




