/*
 * buttons_control_block.c
 *
 *  Created on: Nov 25, 2024
 *      Author: ACER
 */

//--- Private Include ----------------------------

#include "buttons_control_block.h"

//--- Variables ----------------------------------
//- Global Variables -----------------------------
uint8_t bcb_state = BCB_RFID;

//--- Function Definition ------------------------

/*	Function: bcb_init(void)
 * 	Return: none
 * 	Purpose: initial all requirements
 */
void bcb_init(void){
	keypad_init();
	password_reset();
	//lcdcb_init();
	bcb_state = BCB_RFID;
}

/*	Function: bcb_run(void)
 * 	Return: none
 * 	Purpose: run button control block to determine the mode
 */
void bcb_run(void){
	switch(bcb_state){
	case BCB_RFID:
		if(keypad_run() == 'e' && lcdcb_state == LCDCB_REQUEST){
			bcb_state = BCB_PASSWORD;
			lcdcb_state = LCDCB_PASSWORD;
			password_reset();
		}
		break;
	case BCB_PASSWORD:
		char c = keypad_run();
		password_run(c);
		lcdcb_run();
		if(c == 'e' && flag_password_correct == PASSWORD_WRONG){
			lcdcb_state = LCDCB_WRONG_PASSWORD;
			password_reset();
			timer_set(TIMER_LCD_WRONG_PASSWORD_FLAG, TIMER_LCD_WRONG_PASSWORD_TIME);
			break;
		}
		if(c == 'e' && flag_password_correct == PASSWORD_CORRECT){
			bcb_state = BCB_RFID;
			dcb_state = DCB_OPEN;
			lcdcb_state = LCDCB_WELCOME;
			password_reset();
			timer_set(TIMER_DOOR_OPEN_FLAG, TIMER_DOOR_OPEN_TIME);
			break;
		}
		if(c == 'e' && flag_password_correct == PASSWORD_FLOATING){
			bcb_state = BCB_RFID;
			lcdcb_state = LCDCB_REQUEST;
			lcd_clear_display();
			break;
		}
		break;
	default:
		break;
	}
}

//--- Preprocessors ------------------------------
