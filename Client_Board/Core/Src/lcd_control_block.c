/*
 * lcd_control_block.c
 *
 *  Created on: Nov 25, 2024
 *      Author: ACER
 */

//--- Private Include ----------------------------

#include "lcd_control_block.h"

//--- Variables ----------------------------------

uint8_t lcdcb_state;

//--- Function Definition ------------------------
//- Local Functions ------------------------------

/*	Function: lcdcb_request(void)
 * 	Return: none
 * 	Purpose: print out request scene;
 */
void lcdcb_request(void){
	lcd_goto_XY(1,0);
	lcd_send_string("XIN MOI QUET THE");
	lcd_goto_XY(2,0);
	lcd_send_string("................");
}

/*	Function: lcdcb_init(void)
 * 	Return: none
 * 	Purpose: print out welcome scene;
 */
void lcdcb_welcome(void){
	lcd_goto_XY(1,0);
	lcd_send_string("     MOI VAO    ");
	lcd_goto_XY(2,0);
	lcd_send_string("................");
}

/*	Function: lcdcb_init(void)
 * 	Return: none
 * 	Purpose: print out password typing scene;
 */
void lcdcb_password(void){
	lcd_goto_XY(1,0);
	lcd_send_string("  NHAP MAT KHAU ");
	lcd_goto_XY(2,0);
	for(uint8_t i = 0; i<16; ++i){
		if(i>=5 && i<5+password_get_typed_index()){
			lcd_send_string("*");
			continue;
		}
		lcd_goto_XY(2,i);
		lcd_send_string(" ");
	}
}

/*	Function: lcdcb_init(void)
 * 	Return: none
 * 	Purpose: print out wrong password scene;
 */
void lcdcb_wrong_password(void){
	lcd_goto_XY(1,0);
	lcd_send_string("  SAI MAT KHAU  ");
	lcd_goto_XY(2,0);
	lcd_send_string("  HAY NHAP LAI  ");
}

//- Global Functions -----------------------------

/*	Function: lcdcb_init(void)
 * 	Return: none
 * 	Purpose: initial all requirements;
 */
void lcdcb_init(void){
	lcd_init();
	lcdcb_state = LCDCB_REQUEST;
}

/*	Function: lcdcb_run(void)
 * 	Return: none
 * 	Purpose: run lcd control block;
 */
void lcdcb_run(void){
	switch(lcdcb_state){
	case LCDCB_REQUEST:
		lcdcb_request();
		break;
	case LCDCB_WELCOME:
		lcdcb_welcome();
		if(timer_flag[1] == 1){
			lcdcb_state = LCDCB_REQUEST;
			timer_flag[1] = 0;
		}
		break;
	case LCDCB_PASSWORD:
		lcdcb_password();
		break;
	case LCDCB_WRONG_PASSWORD:
		lcdcb_wrong_password();
		if(timer_flag[2] == 1){
			lcdcb_state = LCDCB_PASSWORD;
			timer_flag[2] = 0;
		}
		break;
	default:
		break;
	}
}

//--- Preprocessors ------------------------------

