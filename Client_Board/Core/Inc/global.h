/*
 * global.h
 *
 *  Created on: Nov 10, 2024
 *      Author: ADMIN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

//--- Private Include ----------------------------

#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "MFRC522.h"
#include "queue.h"
#include "timer.h"
#include "list_person.h"
#include "i2c_lcd.h"

//--- Variables ----------------------------------

extern uint8_t data_byte_receive[1];
extern uint8_t ESP_Response[1000];

extern char buffer[50];
extern char SSID[];
extern char Pass[];
extern char Link_ID;
extern char store_char;

extern int count_data_come;
extern int command_size;
extern int Flag_Response;
extern int idx;

extern char* page1;
extern char *page2_Top;
extern char *page2_end;
extern char *table;

extern uint8_t UID[5];
extern uint8_t store_UID[5];

extern int Server_State;

//--- Preprocessors ------------------------------

#define INIT_DOOR 0
#define CLOSE_DOOR 1
#define OPEN_DOOR 2





#endif /* INC_GLOBAL_H_ */
