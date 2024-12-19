/*
 * list_check_in.h
 *
 *  Created on: Nov 29, 2024
 *      Author: ADMIN
 */

#ifndef INC_LIST_CHECK_IN_H_
#define INC_LIST_CHECK_IN_H_
#include "stdint.h"
#include "stm32f1xx_hal.h"
extern UART_HandleTypeDef huart3;
struct person{
	char name[48];
	char* uid;
	char iden[10];
};
struct checkin_data{
	struct person people;
	uint8_t hour[3];
	uint8_t min[3];
	uint8_t sec[3];
	uint8_t day[3];
	uint8_t month[3];
	uint8_t year[3];
};
struct list_checkin_data{
	struct checkin_data list[100];
	int head;
	int tail;
	int size;
};
extern struct list_checkin_data lst;
extern struct person list_person[10];
extern int size;
void init_person(struct person* person);
void add_person(char *name,char* iden);
void init_list_person();
void init_list_checkin_data();
void updatePresent(uint8_t* uid, uint8_t* hour_receive,uint8_t* min_receive,uint8_t* sec_receive,uint8_t* day_receive,uint8_t* month_receive,uint8_t* year_receive);
void add_checkin_data(struct person people, uint8_t* hour, uint8_t* min,uint8_t* sec,uint8_t* day,uint8_t* month,uint8_t* year);
#endif /* INC_LIST_CHECK_IN_H_ */
