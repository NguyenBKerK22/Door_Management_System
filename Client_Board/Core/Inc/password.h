/*
 * password.h
 *
 *  Created on: Nov 12, 2024
 *      Author: ACER
 */

#ifndef INC_PASSWORD_H_
#define INC_PASSWORD_H_

//--- Private Include ----------------------------

#include "main.h"
#include "keypad.h"

//--- Variables ----------------------------------

extern uint8_t flag_password_correct;

//--- Functions Declaration ----------------------
//--- Global Functions ---------------------------
void password_init(void);
void password_reset(void);
void password_run(char c);
uint8_t password_get_typed_index(void);

//--- Preprocessing ------------------------------

#define PASSWORD_LENGTH 	6
#define PASSWORD_WRONG		0
#define PASSWORD_CORRECT	1
#define PASSWORD_FLOATING	2


#endif /* INC_PASSWORD_H_ */
