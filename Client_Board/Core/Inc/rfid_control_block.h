/*
 * rfid_control_block.h
 *
 *  Created on: Nov 25, 2024
 *      Author: ACER
 */

#ifndef INC_RFID_CONTROL_BLOCK_H_
#define INC_RFID_CONTROL_BLOCK_H_

//--- Private Include ----------------------------

#include "global.h"
#include "MFRC522.h"
#include "lcd_control_block.h"
#include "door_control_block.h"
#include "rtc_control_block.h"
//--- Variables ----------------------------------

extern uint8_t rfidcb_state;

//--- Function Declaration -----------------------
//--- Global Functions ---------------------------
void rfidcb_init(void);
void rfidcb_run(void);









#endif /* INC_RFID_CONTROL_BLOCK_H_ */
