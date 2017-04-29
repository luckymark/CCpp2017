#include "Queue.h"
#include <iostream>
using namespace std;

void Queue::append(int num){
	if(!is_Full){
		data[tail]=num;
		tail++;
		if(is_Empty){
			is_Empty = 0;
		}
		if(tail > 99){
			tail = 0;
		}
		if(tail == head){
			is_Full = 1;
		}
	}
	else{
		cout<<"APPEND ERROR 001"<<endl;
	}
}

int Queue::pop(){
	if(!is_Empty){
		head++;
		if(is_Full){
			is_Full = 0;
		}
		if(head>99){
			head = 0;
		}
		if(head == tail){
			is_Empty = 1;
		}
		if(head==0){
			return data[99];
		}
		else{
			return data[head-1];
		}
	}
	else{
		cout<<"POP ERROR 001 RETURN -23333333"<<endl;
		return -23333333;
	}
}
