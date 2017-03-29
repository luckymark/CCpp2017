#include <cstring>
#include "Queue.h"
#include <iostream>

void Queue::clear(){
	memset(element,0,sizeof(element));
	head=tail=0;
}

void Queue::append(int x){
	if ((tail+1)%MAXQUEUE==head) {
		std::cerr<<"Full! Can not add anymore!\n";
		return;
	}
	tail++;
	if (tail==MAXQUEUE) tail=0;
	element[tail]=x;
}

void Queue::pop(){
	if (head!=tail) {
		head++;
		if (head==MAXQUEUE) head=0;
	}
}

int Queue::front(){
	return element[head+1];
}

bool Queue::isfull(){
	return (tail)%MAXQUEUE==head;
}

bool Queue::isempty(){
	return head==tail;
}

