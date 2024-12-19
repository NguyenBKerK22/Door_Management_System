/*
 * rtc_control_block.h
 *
 *  Created on: Nov 28, 2024
 *      Author: ADMIN
 */

#ifndef INC_RTC_CONTROL_BLOCK_H_
#define INC_RTC_CONTROL_BLOCK_H_

//--- Private Include ----------------------------

#include "main.h"

//--- Variables ----------------------------------
extern RTC_TimeTypeDef sTime;
extern RTC_DateTypeDef sDate;
extern RTC_HandleTypeDef hrtc;
//--- Functions Declaration ----------------------
//--- Global Functions ---------------------------
void rtccb_BCD2STRING(uint8_t data, uint8_t* arr,int index);
void rtccb_get_time(uint8_t* frame);
void rtccb_get_date(uint8_t* frame);

//--- Preprocessing ------------------------------

#endif /* INC_RTC_CONTROL_BLOCK_H_ */
