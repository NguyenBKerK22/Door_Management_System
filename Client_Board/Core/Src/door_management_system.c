/*
 * door_management_system.c
 *
 *  Created on: Nov 24, 2024
 *      Author: ACER
 */

//--- Private Include ----------------------------

#include "door_management_system.h"

//--- Variables ----------------------------------
//- Local Variables ------------------------------
static uint8_t dms_mode;

//--- Functions Definition -----------------------
//- Global Functions -----------------------------

/*	Function: dms_init(void)
 * 	Return: none
 * 	Purpose: initial all requirements;
 */
void dms_init(void){
	dms_mode = MODE_RFID;
	rfidcb_init();
	bcb_init();
	dcb_init();
}

/*	Function: dms_run(void)
 * 	Return: none
 * 	Purpose: run door management system;
 */
void dms_run(void){
	switch(dms_mode){
	case MODE_RFID:
		rfidcb_run();
		bcb_run();
		dcb_run();
		if(bcb_state == MODE_PASSWORD){
			dms_mode = MODE_PASSWORD;
			password_reset();
			break;
		}
		break;
	case MODE_PASSWORD:
		bcb_run();
		dcb_run();
		if(bcb_state == MODE_RFID){
			dms_mode = MODE_RFID;
			break;
		}
		break;
	}
}
