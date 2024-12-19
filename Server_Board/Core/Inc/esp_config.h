/*
 * esp_config.h
 *
 *  Created on: Nov 28, 2024
 *      Author: ADMIN
 */

#ifndef INC_ESP_CONFIG_H_
#define INC_ESP_CONFIG_H_
#include "stm32f1xx_hal.h"
#include "list_check_in.h"
#include "string.h"
#include "stdio.h"
extern char SSID[];
extern char Pass[];

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart3;

extern uint8_t data_byte_receive[1];
extern uint8_t ESP_Response[1000];

extern char buffer[50];
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

#define ON_SERVER 0
#define OFF_SERVER 1

void ESP_INIT();
void SendCommand(char* str);
void WaitForResponse(int timeout,char* OKE_response,char* Error_response);
void Server_Send(int linkID,char* str);
void Server_On();
#endif /* INC_ESP_CONFIG_H_ */
