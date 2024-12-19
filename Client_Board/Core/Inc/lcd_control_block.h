/*
 * lcd_control_block.h
 *
 *  Created on: Nov 25, 2024
 *      Author: ACER
 */

#ifndef INC_LCD_CONTROL_BLOCK_H_
#define INC_LCD_CONTROL_BLOCK_H_

//--- Private Include ----------------------------

#include "main.h"
#include "timer.h"
#include "i2c_lcd.h"
#include "buttons_control_block.h"

//--- Variables ----------------------------------

extern uint8_t lcdcb_state;

//--- Function Declaration -----------------------
//--- Global Functions ---------------------------
void lcdcb_init(void);
void lcdcb_run(void);

//--- Preprocessors ------------------------------

#define LCDCB_WELCOME   	  9
#define LCDCB_REQUEST  		 10
#define LCDCB_PASSWORD 		 11
#define LCDCB_WRONG_PASSWORD 12



#endif /* INC_LCD_CONTROL_BLOCK_H_ */
