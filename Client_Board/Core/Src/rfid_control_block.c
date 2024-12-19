/*
 * rfid_control_block.c
 *
 *  Created on: Nov 25, 2024
 *      Author: ACER
 */

//--- Private Include ----------------------------

#include "rfid_control_block.h"
//--- Function Definition ------------------------

/*	Function: rfidcb_init(void)
 * 	Return: none
 * 	Purpose: initial all requirements;
 */
void rfidcb_init(void){
	MFRC522_Init();
	init();
	lcdcb_init();
	timer_set(TIMER_RFID_DEBOUNCE_FLAG, TIMER_RFID_DEBOUNCE_TIME);
}

/*	Function: rfidcb_run(void)
 * 	Return: none
 * 	Purpose: run rfid control block;
 */
void rfidcb_run(void){
	if(MFRC522_Request(PICC_REQIDL, UID) == MI_OK && MFRC522_Anticoll(UID) == MI_OK && timer_flag[3] == 1){
		timer_set(3, 500);
		UID[4] = '\0';
		if(updatePresent((char*)UID) == 1){
			dcb_state = DCB_OPEN;
			lcdcb_state = LCDCB_WELCOME;
			timer_set(TIMER_DOOR_OPEN_FLAG, TIMER_DOOR_OPEN_TIME);
			uint8_t frame[16];
			strcpy((char*)frame,(char*)UID);
			rtccb_get_time(frame);
			rtccb_get_date(frame);
			HAL_UART_Transmit(&huart3,frame,16,HAL_MAX_DELAY);
		}
	}
	lcdcb_run();
}
