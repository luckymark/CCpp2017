#include "Queue.h"

bool Queue::isEmpty(){
	return !length;
}

bool Queue::isFull(){
	return length;
}

void Queue::appand(int number){
	tail+=1;
	queue[tail]=number;
	length+=1;
}

void Queue::pop(){
	head+=1;
	length-=1;
}
