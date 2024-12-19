/*
 * door_control_block.h
 *
 *  Created on: Nov 25, 2024
 *      Author: ACER
 */

#ifndef INC_DOOR_CONTROL_BLOCK_H_
#define INC_DOOR_CONTROL_BLOCK_H_

//--- Private Include ----------------------------

#include "main.h"
#include "timer.h"
#include "MFRC522.h"
#include "rgb_control_block.h"

//--- Variables ----------------------------------

extern uint8_t dcb_state;
extern TIM_HandleTypeDef htim1;

//--- Function Declaration -----------------------
//- Global Functions -----------------------------
void dcb_init(void);
void dcb_run(void);

//--- Preprocessors ------------------------------

#define DCB_OPEN  1
#define DCB_CLOSE 2


#endif /* INC_DOOR_CONTROL_BLOCK_H_ */
