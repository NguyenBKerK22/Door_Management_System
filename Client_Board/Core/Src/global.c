/*
 * global.c
 *
 *  Created on: Nov 28, 2024
 *      Author: ADMIN
 */

#include "global.h"
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
		<html>\n\
		<body>\n\
		<h1>ESP8266 USER DATA COLLECTION</h1>\n\
		<h2> DATA STORED Successfully </h2>\n\
		<p> Click Below to Submit again </p>\n\
		<form action=\"/home\">\n\
		<input type=\"submit\" value=\"Submit Again\">\n\
		</form><br><br>\n\
		<form action=\"/page2\">\n\
		<input type=\"submit\" value=\"View Data\">\n\
		</form>\n\
		</body></html>";

char *page2_Top = "<!DOCTYPE html>\n\
					<meta http-equiv='refresh' content='4'/>\n\
					<html>\n\
					<head>\n\
					<title> RFID systems</title>\n\
					<style>\n\
 					td, th {\n\
  							text-align: center;\n\
  							padding: 8px;\n\
						}\n\
						th{\n\
  							background-color: #E0FFFF;\n\
						}\n\
						tr:nth-child(even) {\n\
  						background-color: #dddddd;\n\
				 }";
char *table = "<style>table {\n\
  							font-family: arial, sans-serif;\n\
  							border-collapse: collapse; \n\
  							width: 100%;\n\
  							border-radius:15px;\n\
  							outline: 2px solid black;\n\
  							overflow:hidden;\n\
							}\n\
				</style><table><tr><th style=\"border-bottom:2px solid black\">Full name</th>\n\
    			<th style=\"border-bottom:2px solid black;border-left:2px solid black;border-right:2px solid black\">Identify</th>\n\
    			<th style=\"border-bottom:2px solid black\">Time</th>\n\
				</tr>";
//--------------------------------------------------------------------------------------
uchar UID[5];
uchar store_UID[5] = "";
