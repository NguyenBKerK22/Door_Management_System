/*
 * door_control_block.c
 *
 *  Created on: Nov 25, 2024
 *      Author: ACER
 */

//--- Private Include ----------------------------

#include "door_control_block.h"

//--- Variables ----------------------------------

uint8_t dcb_state;

//--- Function Definition ------------------------

/*	Function: dcb_init(void)
 * 	Return: none
 * 	Purpose: initial all requirements;
 */
void dcb_init(void){
	dcb_state = DCB_CLOSE;
	rgbcb_init();
}

/*	Function: bcb_run(void)
 * 	Return: none
 * 	Purpose: run door control block to determine it should open or not;
 */
void dcb_run(void){
	switch(dcb_state){
		case DCB_CLOSE:
			htim1.Instance->CCR1 = 25;
			rgbcb_state = RGB_RED;
			MFRC522_Halt();
			break;
		case DCB_OPEN:
			htim1.Instance->CCR1 = 75;
			rgbcb_state = RGB_GREEN;
			if(timer_flag[1] == 1){
				dcb_state = DCB_CLOSE;
			}
			break;
		default:
			break;
	}
	rgbcb_run();

}

//--- Preprocessors ------------------------------

