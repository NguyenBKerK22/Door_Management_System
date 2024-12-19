/*
 * timer.h
 *
 *  Created on: Nov 8, 2024
 *      Author: ADMIN
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

//--- Variables ----------------------------------

extern int timer_flag[10];

//--- Function Declaration -----------------------
//--- Global Functions ---------------------------
void timer_set(int index, int duration);
void timer_run(void);

//--- Preprocessors ------------------------------
//- TICK in ms -----------------------------------
#define TICK_HTIM2 5

//- TOTAL SOFTWARE TIMER -------------------------
#define TOTAL_SOFTWARE_TIMERS 10

//- DEFINING EACH SOFTWARE TIMER PURPOSE ---------
#define TIMER_RFID_DEBOUNCE_FLAG 	  0
#define TIMER_RFID_DEBOUNCE_TIME 	  500
#define TIMER_DOOR_OPEN_FLAG 		  1
#define TIMER_DOOR_OPEN_TIME 		  5000
#define TIMER_LCD_WRONG_PASSWORD_FLAG 2
#define TIMER_LCD_WRONG_PASSWORD_TIME 2000



#endif /* INC_TIMER_H_ */
