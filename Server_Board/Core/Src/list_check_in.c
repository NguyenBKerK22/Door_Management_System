/*
 * list_check_in.c
 *
 *  Created on: Nov 29, 2024
 *      Author: ADMIN
 */


#include "list_check_in.h"
#include "string.h"
//--- Variables ----------------------------------
//--- Local Variables ----------------------------
char uid[10][5] = {{0xEF,0xBE,0x16,0x1E,0x00},
				   {0xFF,0x8C,0x9A,0x1E,0x00},
		           {0xBF,0xE1,0x76,0x1F,0x00},
				   {0xEF,0xF3,0x20,0x1E,0x00},
				   {0x00,0x00,0x00,0x00,0x00},
				   {0x00,0x00,0x00,0x00,0x00},
				   {0x00,0x00,0x00,0x00,0x00},
				   {0x00,0x00,0x00,0x00,0x00},
				   {0x00,0x00,0x00,0x00,0x00},
				   {0x00,0x00,0x00,0x00,0x00}
};

//--- Global Variables ---------------------------
struct person list_person[10];
struct list_checkin_data lst;
int size = 0;
//--- Functions Definition -----------------------
//--- Global Functions ---------------------------
void add_person(char *name, char* iden){
		if(size >= 10) return;
		strcpy(list_person[size].name,name);
		list_person[size].uid = uid[size];
		strcpy(list_person[size].iden,iden);
		size++;
}

void init_person(struct person* person){
	memset(person->iden,0,sizeof(person->iden));
	memset(person->name,0,sizeof(person->name));
	person->uid = NULL;
}
void init_list_person(){
	for(int i=0;i<10;i++){
		init_person(&list_person[i]);
	}
	add_person("Do Hoan Nguyen","2212285");
	add_person("Phan Minh Trong","22122xx");
	add_person("Nguyen Phuong Nguyen","22122xx");
}

void updatePresent(uint8_t* uid, uint8_t* hour_receive,uint8_t* min_receive,uint8_t* sec_receive,uint8_t* day_receive,uint8_t* month_receive,uint8_t* year_receive){
	for(int i=0;i<size;i++){
		if(strcmp((char*)list_person[i].uid,(char*)uid)==0){
				add_checkin_data(list_person[i],hour_receive,min_receive,sec_receive,day_receive,month_receive,year_receive);
				return;
		}
	}
}
void init_list_checkin_data(){
	lst.head = 0;
	lst.tail = 0;
	lst.size = 0;
	for(int i=0;i<100;i++){
		init_person(&lst.list[i].people);
	}
}
void add_checkin_data(struct person people, uint8_t* hour, uint8_t* min,uint8_t* sec,uint8_t* day,uint8_t* month,uint8_t* year){
	int index = lst.size;
	strcpy(lst.list[index].people.iden,people.iden);
	strcpy(lst.list[index].people.name,people.name);
	lst.list[index].people.uid = people.uid;
	strcpy((char*)lst.list[index].hour,(char*)hour);
	strcpy((char*)lst.list[index].min,(char*)min);
	strcpy((char*)lst.list[index].sec,(char*)sec);
	strcpy((char*)lst.list[index].day,(char*)day);
	strcpy((char*)lst.list[index].month,(char*)month);
	strcpy((char*)lst.list[index].year,(char*)year);
	lst.size++;
	if(lst.size > 100) lst.size = 0;
}
