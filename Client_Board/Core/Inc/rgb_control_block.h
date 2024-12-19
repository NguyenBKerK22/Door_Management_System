/*
 * rgb_control_block.h
 *
 *  Created on: Nov 26, 2024
 *      Author: ACER
 */

#ifndef INC_RGB_CONTROL_BLOCK_H_
#define INC_RGB_CONTROL_BLOCK_H_

//--- Private Include ----------------------------

#include "main.h"

//--- Variables ----------------------------------

extern uint8_t rgbcb_state;

//--- Function Declaration -----------------------
//--- Global Functions ---------------------------
void rgbcb_init(void);
void rgbcb_run(void);

//--- Preprocessors ------------------------------

#define RGB_RED    1
#define RGB_GREEN  2


#endif /* INC_RGB_CONTROL_BLOCK_H_ */
