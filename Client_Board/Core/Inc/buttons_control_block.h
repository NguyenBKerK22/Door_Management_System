/*
 * buttons_control_block.h
 *
 *  Created on: Nov 25, 2024
 *      Author: ACER
 */

#ifndef INC_BUTTONS_CONTROL_BLOCK_H_
#define INC_BUTTONS_CONTROL_BLOCK_H_

//--- Private Include ----------------------------

#include "main.h"
#include "password.h"
#include "keypad.h"
#include "lcd_control_block.h"
#include "door_control_block.h"

//--- Variables ----------------------------------

extern uint8_t bcb_state;

//--- Function Declaration -----------------------
//- Global Functions -----------------------------
void bcb_init(void);
void bcb_run(void);

//--- Preprocessors ------------------------------

#define BCB_RFID	 10
#define BCB_PASSWORD 11



#endif /* INC_BUTTONS_CONTROL_BLOCK_H_ */
