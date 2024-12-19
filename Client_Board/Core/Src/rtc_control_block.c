/*
 * rtc_control_block.c
 *
 *  Created on: Nov 28, 2024
 *      Author: ADMIN
 */



//--- Private Include ----------------------------

#include "rtc_control_block.h"

//--- Variables ----------------------------------
RTC_TimeTypeDef sTime;
RTC_DateTypeDef sDate;

//--- Functions Definition -----------------------
//--- Global Functions ---------------------------
void rtccb_BCD2STRING(uint8_t data, uint8_t* arr,int index){
	uint8_t temp = (data >> 4) * 10 + (data & 0x0f);
	arr[index] = temp/10 + 48;
	arr[index+1] = temp%10 + 48;
}

void rtccb_get_time(uint8_t* frame){
	HAL_RTC_GetTime(&hrtc, &sTime,RTC_FORMAT_BCD);
	rtccb_BCD2STRING(sTime.Hours, frame,4);
	rtccb_BCD2STRING(sTime.Minutes, frame,6);
	rtccb_BCD2STRING(sTime.Seconds, frame,8);
}

void rtccb_get_date(uint8_t* frame){
	HAL_RTC_GetDate(&hrtc, &sDate,RTC_FORMAT_BCD);
	rtccb_BCD2STRING(sDate.Date, frame,10);
	rtccb_BCD2STRING(sDate.Month, frame,12);
	rtccb_BCD2STRING(sDate.Year, frame,14);
}
