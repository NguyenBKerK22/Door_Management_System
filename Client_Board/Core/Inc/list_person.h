/*
 * list_person.h
 *
 *  Created on: Nov 8, 2024
 *      Author: ADMIN
 */

#ifndef INC_LIST_PERSON_H_
#define INC_LIST_PERSON_H_

//--- Variables ----------------------------------
//--- Private Struct -----------------------------
struct person{
	char name[48];
	char* uid;
	char iden[10];
};

extern struct person list_person[10];
extern int size;

//--- Global Functiosn ---------------------------

void add(char *name,char* iden);
void init_list_person();
int updatePresent(char* uid);


#endif /* INC_LIST_PERSON_H_ */
