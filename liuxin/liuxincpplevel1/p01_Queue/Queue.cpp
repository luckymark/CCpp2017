#include <cstdlib>
#include <iostream>
#include "Queue.h"

Queue::Queue(int x){
	element=(int *)malloc(sizeof(int)*x);
}
Queue::~Queue(){
	free(element);
}

void Queue::clear(){
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

