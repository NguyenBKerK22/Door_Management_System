/*
 * rgb_control_block.c
 *
 *  Created on: Nov 26, 2024
 *      Author: ACER
 */

//--- Private Include ----------------------------

#include "rgb_control_block.h"

//--- Variables ----------------------------------

uint8_t rgbcb_state;

//--- Function Definition ------------------------

/*	Function: rgbcb_init(void)
 * 	Return: none
 * 	Purpose: initial all requirements;
 */
void rgbcb_init(void){
	rgbcb_state = RGB_RED;
	HAL_GPIO_WritePin(RGB_R_GPIO_Port, RGB_R_Pin, 1);
	HAL_GPIO_WritePin(RGB_G_GPIO_Port, RGB_G_Pin, 0);
}

/*	Function: rgbcb_run(void)
 * 	Return: none
 * 	Purpose: run rgb control block;
 */
void rgbcb_run(void){
	switch(rgbcb_state){
	case RGB_RED:
		HAL_GPIO_WritePin(RGB_R_GPIO_Port, RGB_R_Pin, 1);
		HAL_GPIO_WritePin(RGB_G_GPIO_Port, RGB_G_Pin, 0);
		break;
	case RGB_GREEN:
		HAL_GPIO_WritePin(RGB_R_GPIO_Port, RGB_R_Pin, 0);
		HAL_GPIO_WritePin(RGB_G_GPIO_Port, RGB_G_Pin, 1);
		break;
	default:
		break;
	}
}


