/*
 * esp_config.c
 *
 *  Created on: Nov 28, 2024
 *      Author: ADMIN
 */
#include "esp_config.h"
uint8_t data_byte_receive[1];
uint8_t ESP_Response[1000];
//----------------------------------
char buffer[50]="";
char SSID[]="\"v\"";
char Pass[]="\"12345678\"";
char Link_ID = '\n';
char store_char ='\n';
//----------------------------------
int count_data_come = 0;
int command_size = 0;
int Flag_Response = 0;
int idx = 0;
// HTML USED FOR WEBSERVER
//-------------------------------------------------------------------------------------
char *page1 = "<!DOCTYPE html>\n\
<html lang=\"en\">\n\
<head>\n\
    <meta charset=\"UTF-8\">\n\
    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n\
    <title>Door Management System</title>\n\
    <style>\n\
        body {\n\
            font-family: Arial, sans-serif;\n\
            margin: 0;\n\
            padding: 0;\n\
            display: flex;\n\
            justify-content: center;\n\
            align-items: center;\n\
            height: 100vh;\n\
            background-color: #f4f4f9;\n\
        }\n\
        h1 {\n\
            color: #333;\n\
            font-size: 2rem;\n\
            margin-bottom: 20px;\n\
        }\n\
        form {\n\
            text-align: center;\n\
        }\n\
        input[type=\"submit\"] {\n\
            padding: 10px 20px;\n\
            font-size: 1rem;\n\
            color: white;\n\
            background-color: #007bff;\n\
            border: none;\n\
            border-radius: 5px;\n\
            cursor: pointer;\n\
            transition: background-color 0.3s ease;\n\
        }\n\
        input[type=\"submit\"]:hover {\n\
            background-color: #0056b3;\n\
        }\n\
    </style>\n\
</head>\n\
<body>\n\
    <div>\n\
        <h1>DOOR MANAGEMENT SYSTEM</h1>\n\
        <form action=\"/page2\">\n\
            <input type=\"submit\" value=\"View Data\">\n\
        </form>\n\
    </div>\n\
</body>\n\
</html>"
;

char *page2_Top = "<!DOCTYPE html>\n\
<html lang=\"en\">\n\
<head>\n\
    <meta charset=\"UTF-8\">\n\
    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n\
    <meta http-equiv='refresh' content='4'/>\n\
    <title>RFID Systems</title>\n\
    <style>\n\
        body {\n\
            font-family: Arial, sans-serif;\n\
            background-color: #f4f4f9;\n\
            margin: 0; padding: 0;\n\
        }\n\
        h1 {\n\
            text-align: center;\n\
            margin: 20px 0;\n\
        }\n\
        table {\n\
            width: 90%;\n\
            margin: 20px auto;\n\
            border-collapse: collapse;\n\
            border: 2px solid black;\n\
            border-radius: 15px;\n\
            overflow: hidden;\n\
        }\n\
        th, td {\n\
            padding: 8px;\n\
            text-align: center;\n\
        }\n\
        th {\n\
            background-color: #E0FFFF;\n\
        }\n\
        tr:nth-child(even) {\n\
            background-color: #ddd;\n\
        }\n\
    </style>\n\
</head>\n\
<body>\n\
    <h1>RFID Systems</h1>\n\
    <table>\n\
        <tr>\n\
            <th>Full Name</th>\n\
            <th>Identify</th>\n\
            <th>Time</th>\n\
            <th>Date</th>\n\
            <tr>\n\
";
char *table = "<style>table {\n\
  					font-family: arial, sans-serif;\n\
  					border-collapse: collapse; \n\
  					width: 100%;\n\
  					border-radius:15px;\n\
  					outline: 2px solid black;\n\
  					overflow:hidden;\n\
				}\n\
				</style><table><tr><th style=\"border-top:2px solid black;border-bottom:2px solid black;border-left:2px solid black;border-right:2px solid black\">Full name</th>\n\
    			<th style=\"border-top:2px solid black;border-bottom:2px solid black;border-left:2px solid black;border-right:2px solid black\">Identify</th>\n\
    			<th style=\"border-top:2px solid black;border-bottom:2px solid black;border-left:2px solid black;border-right:2px solid black\">Time</th>\n\
				<th style=\"border-top:2px solid black;border-bottom:2px solid black;border-left:2px solid black;border-right:2px solid black\">Date</th>\n\
				</tr>";
//--------------------------------------------------------------------------------------
unsigned char UID[5];
unsigned char store_UID[5] = "";

int Server_State = OFF_SERVER;

void SendCommand(char* str){
	command_size = strlen(str);
	HAL_UART_Transmit(&huart1,(uint8_t*)str,strlen(str),HAL_MAX_DELAY);
	if(Server_State == OFF_SERVER) HAL_UART_Receive_IT(&huart1, data_byte_receive,1);
}
void WaitForResponse(int timeout,char* OKE_response,char* Error_response){
	uint32_t tickStart = HAL_GetTick();
		while(Flag_Response == 0){
			if(HAL_GetTick()-tickStart > timeout){
				count_data_come = 0;
				idx=0;
				command_size=0;
				return;
			}
			if(strstr((char*)ESP_Response,OKE_response) != NULL){
				Flag_Response = 1;
			}
			else if(strstr((char*)ESP_Response,Error_response) != NULL){
				Flag_Response = 2;
			}
		}
		idx=0;
		command_size =0;
		count_data_come = 0;
}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle){
	if(Flag_Response == 0||Server_State==ON_SERVER) HAL_UART_Receive_IT(&huart1, data_byte_receive, 1);
		count_data_come++;
		if(count_data_come > command_size){
			ESP_Response[idx++] = data_byte_receive[0];
			if(idx>=1000){ //+IPD
				idx = 0;
			}
		}
}
void ESP_INIT(){
	SendCommand("AT+RESTORE\r\n");
	WaitForResponse(20000,"ready\r\n","ERROR\r\n");
	memset(ESP_Response,0,sizeof(ESP_Response));
	if(Flag_Response==1){
		HAL_UART_Transmit(&huart3,(uint8_t*)"AT rst OKE\r",sizeof("AT rst OKE\r"),HAL_MAX_DELAY);
	}
	else if(Flag_Response==2){
		HAL_UART_Transmit(&huart3,(uint8_t*)"AT rst ERROR\r",sizeof("AT rst ERROR\r"),HAL_MAX_DELAY);
	}
	Flag_Response = 0;
	SendCommand("AT+CWMODE=1\r\n");
	WaitForResponse(5000,"OK\r\n","ERROR\r\n");
	memset(ESP_Response,0,sizeof(ESP_Response));
	if(Flag_Response==1){
		HAL_UART_Transmit(&huart3,(uint8_t*)"AT CWMODE OKE\r",sizeof("AT CWMODE OKE\r"),HAL_MAX_DELAY);
	}
	else if(Flag_Response==2){
		HAL_UART_Transmit(&huart3,(uint8_t*)"AT CWMODE ERROR\r",sizeof("AT CWMODE ERROR\r"),HAL_MAX_DELAY);
	}
	Flag_Response = 0;
	sprintf(buffer,"AT+CWJAP=%s,%s\r\n",SSID,Pass);
	SendCommand(buffer);
	memset(buffer,0,sizeof(buffer));
	WaitForResponse(20000,"OK\r\n","ERROR\r\n");
	memset(ESP_Response,0,sizeof(ESP_Response));
	if(Flag_Response==1){
		HAL_UART_Transmit(&huart3,(uint8_t*)"AT CWJAP OKE\r",sizeof("AT CWJAP OKE\r"),HAL_MAX_DELAY);
	}
	else if(Flag_Response==2){
		HAL_UART_Transmit(&huart3,(uint8_t*)"AT CWJAP ERROR\r",sizeof("AT CWJAP ERROR\r"),HAL_MAX_DELAY);
	}

	Flag_Response = 0;
	SendCommand("AT+CIPMUX=1\r\n");
	WaitForResponse(5000,"OK\r\n","ERROR\r\n");
	memset(ESP_Response,0,sizeof(ESP_Response));
	if(Flag_Response==1){
		HAL_UART_Transmit(&huart3,(uint8_t*)"AT CIPMUX OKE\r",sizeof("AT CIPMUX OKE\r"),HAL_MAX_DELAY);
		}
	else if(Flag_Response==2){
		HAL_UART_Transmit(&huart3,(uint8_t*)"AT CIPMUX ERROR\r",sizeof("AT CIPMUX ERROR\r"),HAL_MAX_DELAY);
	}

	Flag_Response = 0;
	SendCommand("AT+CIPSERVER=1,80\r\n");
	WaitForResponse(5000,"OK\r\n","ERROR\r\n");
	memset(ESP_Response,0,sizeof(ESP_Response));
	if(Flag_Response==1){
		HAL_UART_Transmit(&huart3,(uint8_t*)"AT CIPSERVER OKE\r",sizeof("AT CIPSERVER OKE\r"),HAL_MAX_DELAY);
	}
	else if(Flag_Response==2){
		HAL_UART_Transmit(&huart3,(uint8_t*)"AT CIPSERVER ERROR\r",sizeof("AT CIPSERVER ERROR\r"),HAL_MAX_DELAY);
	}
	Server_State = ON_SERVER;
	HAL_UART_Receive_IT(&huart1, data_byte_receive, 1);
}
void Server_Send(int linkID,char* str){
	Flag_Response = 0;
	sprintf(buffer,"AT+CIPSEND=%d,%d\r\n",linkID,strlen(str));
	SendCommand(buffer);
	memset(buffer,0,sizeof(buffer));
	WaitForResponse(10000,">","ERROR");
	memset(ESP_Response,0,sizeof(ESP_Response));

	Flag_Response = 0;
	HAL_UART_Transmit(&huart1,(uint8_t*)str,strlen(str),HAL_MAX_DELAY);
	WaitForResponse(20000,"SEND OK","SEND FAIL");
	memset(ESP_Response,0,sizeof(ESP_Response));

	Flag_Response = 0;
	sprintf(buffer,"AT+CIPCLOSE=%d\r\n",linkID);
	SendCommand(buffer);
	memset(buffer,0,sizeof(buffer));
	WaitForResponse(10000,"OK\r\n","ERROR\r\n");
	memset(ESP_Response,0,sizeof(ESP_Response));
}
void Server_On(){
	char* pos = strstr((char*)ESP_Response,"+IPD,");
	if(pos!=NULL){
			store_char = Link_ID;
			Link_ID = (*(pos+5));
	}
	if(store_char == Link_ID && Link_ID >='0' && Link_ID <= '4'){
		if(strstr((char*)ESP_Response,"GET")!=NULL){

		   if(strstr((char*)ESP_Response,"/home")!=NULL){
			    Server_Send(Link_ID-48, page1);
				Flag_Response = 0;
				WaitForResponse(10000, "\r\n", "ERROR\r\n");
				if(Flag_Response == 1) memset(ESP_Response,0,sizeof(ESP_Response));
			}
			else if(strstr((char*)ESP_Response,"/page2")!=NULL){
				char data[4096];
				char localbuf[2048];
				char local_time[10];
				char local_date[10];
				sprintf(data,page2_Top);
				//strcat (data, table);
				for(int i=0;i<lst.size;i++){
					sprintf(local_time,"%s:%s:%s",lst.list[i].hour,lst.list[i].min,lst.list[i].sec);
					sprintf(local_date,"%s/%s/%s",lst.list[i].day,lst.list[i].month,lst.list[i].year);
					sprintf(localbuf,"<td>%s</td>    <td>%s</td>  <td>%s</td>  <td>%s</td></tr>",lst.list[i].people.name,lst.list[i].people.iden,local_time,local_date);
					strcat(data,localbuf);
				}
				strcat (data, "</table>");
				Server_Send(Link_ID-48, data);
				Flag_Response = 0;
				WaitForResponse(10000, "\r\n", "ERROR\r\n");
				if(Flag_Response == 1) memset(ESP_Response,0,sizeof(ESP_Response));
			}
			else if(strstr((char*)ESP_Response,"/ ")!=NULL){
				Server_Send(Link_ID-48, page1);
				Flag_Response = 0;
				WaitForResponse(10000, "\r\n", "ERROR\r\n");
				if(Flag_Response == 1) memset(ESP_Response,0,sizeof(ESP_Response));
			}
		}
	}
}
