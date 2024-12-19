/*
 * queue.c
 *
 *  Created on: Nov 8, 2024
 *      Author: ADMIN
 */


#include <stdio.h>
#include "queue.h"
struct client q[5];
int head=0;
int tail=0;
void init(){
	int i = 0;
	while(i<5){
		q[i].linkID = -1;
		q[i].dataSend = NULL;
		i++;
	}
}
void push(int t,char* buf){
	if(getSize() < max_size){
		if(head==tail && q[head].linkID == -1){
			q[head].linkID = t;
			q[head].dataSend = buf;
		}
		else{
			tail++;
			if(tail >= max_size){
				tail = 0;
			}
			q[tail].linkID = t;
			q[tail].dataSend= buf;
		}
	}

}
void pop(){
	if(getSize()!=0){
		q[head].linkID = -1;
		q[head].dataSend = NULL;
		if(head == tail) return;
		head++;
		if(head >=max_size) head = 0;
	}
}
int top(){
	if(getSize()!=0) return q[head].linkID;
	return -1;
}
int getSize(){
	if(head == tail && q[head].linkID==-1){
		return 0;
	}
	return ((tail-head+1)+max_size)%max_size;
}
