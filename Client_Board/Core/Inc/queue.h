/*
 * queue.h
 *
 *  Created on: Nov 8, 2024
 *      Author: ADMIN
 */

#ifndef INC_QUEUE_H_
#define INC_QUEUE_H_

//--- Variables ----------------------------------
//--- Private Struct ---------------------------
struct client{
	int linkID;
	char* dataSend;
};

//--- Global Variables ---------------------------
extern struct client q[5];
extern int head;
extern int tail;

//--- Functions Declaration ----------------------
//--- Global Functions ---------------------------
void init();
void pop();
void push();
int top();
int getSize();

//--- Preprocessors ------------------------------

#define max_size 5


#endif /* INC_QUEUE_H_ */
