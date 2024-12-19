/*
 * keypad_4x4.h
 *
 *  Created on: Nov 11, 2024
 *      Author: ACER
 */

#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_

//--- Private Include ----------------------------

#include "main.h"
#include "button_processing.h"

//--- Variables ----------------------------------
//- Private struct -------------------------------
typedef struct
{
	GPIO_TypeDef* Port;
	uint16_t 	  Pin;
	char 		  Key;
	uint8_t		  states;
}KEY;

//--- Functions Declaration ----------------------
//--- Global Functions ---------------------------

void keypad_button_reading(void);
void keypad_init(void);
char keypad_run(void);

unsigned char keypad_is_button_pressed(unsigned char index);

//--- Preprocessing ------------------------------
//- TOGGLE TESTING MODE --------------------------
//#define TESTING

//- Total number of button -----------------------
#define TOTAL_BUTTON 13

//- Writing Output For Collums -------------------
#define OFF 					GPIO_PIN_SET
#define ON 						GPIO_PIN_RESET
#define BUTTON_STATUS_PRESSED	ON
#define BUTTON_STATUS_RELEASE	OFF


#endif /* INC_KEYPAD_H_ */
