/*
 * door_management_system.h
 *
 *  Created on: Nov 24, 2024
 *      Author: ACER
 */

#ifndef DOOR_MANAGEMENT_SYSTEM_H_
#define DOOR_MANAGEMENT_SYSTEM_H_

//--- Private Include ----------------------------

#include "main.h"
#include "timer.h"
#include "rfid_control_block.h"
#include "buttons_control_block.h"
#include "door_control_block.h"

//--- Preprocessors ------------------------------

#define MODE_INIT	   9
#define MODE_RFID	  10
#define MODE_PASSWORD 11

//--- Functions Declaration ----------------------
//- Global Functions -----------------------------
void dms_init(void);
void dms_run(void);


#endif /* DOOR_MANAGEMENT_SYSTEM_H_ */
