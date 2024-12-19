/*
 * fsm_button_processing.c
 *
 *  Created on: Nov 12, 2024
 *      Author: ACER
 */

//--- Private Include ----------------------------

#include "button_processing.h"

//--- Variables ----------------------------------
//- Global Variables -----------------------------
uint8_t flag_press = 0;

//--- Functions Definition -----------------------

/*	Function: button_processing_run(uint8_t* state)
 * 	Return: none
 * 	Purpose: processing inputs
 */
void button_processing_run(uint8_t* state, uint8_t index){
	flag_press = 0;
	switch(*state){
		case BUTTON_STATE_RELEASE:
			//TODO
			if(keypad_is_button_pressed(index))
			{
				*state = BUTTON_STATE_PRESSED;
				flag_press = 1;
			}
			break;
		case BUTTON_STATE_PRESSED:
			//TODO
			if(!keypad_is_button_pressed(index))
			{
				*state = BUTTON_STATE_RELEASE;
			}
			break;
		default:
			break;
	}
}




