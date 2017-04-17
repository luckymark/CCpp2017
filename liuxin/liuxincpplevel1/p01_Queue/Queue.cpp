#include <cstdlib>
#include <iostream>
using namespace std;
#include "Queue.h"

Queue::Queue(int x){
	element=new int[x+1];
	len=x+1;
}
Queue::~Queue(){
	delete[] element;
}

void Queue::clear(){
	head=tail=0;
}

void Queue::append(int x){
	//cout<<tail<<' '<<head<<endl;
	if ((tail+1)%len==head) {
		cerr<<"Full! Can not add anymore!\n";
		return;
	}
	tail++;
	if (tail==len) tail=0;
	element[tail]=x;
}

void Queue::pop(){
	if (head!=tail) {
		head++;
		if (head==len) head=0;
	}
}

int Queue::front(){
	return element[(head+1)%len];
}

bool Queue::IsFull(){
	return (tail+1)%len==head;
}

bool Queue::IsEmpty(){
	return head==tail;
}

