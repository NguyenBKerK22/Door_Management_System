/*
 * fsm_button_processing.h
 *
 *  Created on: Nov 12, 2024
 *      Author: ACER
 */

#ifndef INC_BUTTON_PROCESSING_H_
#define INC_BUTTON_PROCESSING_H_

//--- Private Include ----------------------------

#include "main.h"
#include "keypad.h"

//--- Variables ----------------------------------

extern uint8_t flag_press;

//--- Functions Declaration ----------------------
//- Global Functions -----------------------------
void button_processing_run(uint8_t* state, uint8_t index);

//--- Private Defines ----------------------------

#define BUTTON_STATE_RELEASE 1
#define BUTTON_STATE_PRESSED 2


#endif /* INC_BUTTON_PROCESSING_H_ */
