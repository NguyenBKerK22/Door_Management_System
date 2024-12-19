/*
 * timer.c
 *
 *  Created on: Nov 8, 2024
 *      Author: ADMIN
 */

#include "timer.h"

//--- Variables ----------------------------------
//- Local Variables ------------------------------
int timer_counter[10] = {0};

//- Global Variables -----------------------------
int timer_flag[10] = {0};

//--- Functions Declaration ----------------------

/*	Function: timer_set(void)
 * 	Return: none
 * 	Purpose: set timer for each software timer
 */
void timer_set(int index, int duration){
	timer_counter[index] = duration/TICK_HTIM2;
	timer_flag[index] = 0;
}

/*	Function: timer_run(void)
 * 	Return: none
 * 	Purpose: run software timer
 */
void timer_run(void){
	for(int i=0; i<TOTAL_SOFTWARE_TIMERS; i++){
		timer_counter[i]--;
		if(timer_counter[i] <= 0){
			timer_counter[i] = 0;
			timer_flag[i] = 1;
		}
	}
}
