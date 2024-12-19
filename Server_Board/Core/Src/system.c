/*
 * system.c
 *
 *  Created on: Nov 28, 2024
 *      Author: ADMIN
 */
#include "system.h"
int flag_receive = 0;
uint8_t frame[16];
void system_init(){
	init_list_person();
	init_list_checkin_data();
	ESP_INIT();
	HAL_UARTEx_ReceiveToIdle_IT(&huart3,frame ,16 );
}
void system_handle(){
	if(flag_receive==1){
		if(strlen((char*)frame)==0) return;
		uint8_t uid_receive[5];
		uint8_t hour_receive[3];
		uint8_t min_receive[3];
		uint8_t sec_receive[3];
		uint8_t day_receive[3];
		uint8_t month_receive[3];
		uint8_t year_receive[3];
		uid_receive[0] = frame[0];
		uid_receive[1] = frame[1] ;
		uid_receive[2] = frame[2];
		uid_receive[3] = frame[3];
		uid_receive[4] = '\0';
		hour_receive[0] = frame[4];
		hour_receive[1] = frame[5];
		hour_receive[2] = '\0';
		min_receive[0] = frame[6];
		min_receive[1] = frame[7];
		min_receive[2] = '\0';
		sec_receive[0] = frame[8];
		sec_receive[1] = frame[9];
		sec_receive[2] = '\0';
		day_receive[0] = frame[10];
		day_receive[1] = frame[11];
		day_receive[2] = '\0';
		month_receive[0] = frame[12];
		month_receive[1] = frame[13];
		month_receive[2] = '\0';
		year_receive[0] = frame[14];
		year_receive[1] = frame[15];
		year_receive[2] = '\0';
		updatePresent(uid_receive, hour_receive,min_receive,sec_receive,day_receive,month_receive,year_receive);
		flag_receive = 0;
	}
}
void system_on(){
	system_handle();
	Server_On();
}
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
	if(huart->Instance == USART3){
		flag_receive = 1;
		HAL_UARTEx_ReceiveToIdle_IT(&huart3, frame, 16);
	}
}
