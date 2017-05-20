#include "Queue.h"
#include<iostream>
using std::cout;
using std::endl;
void Queue::disp(){
	if(head<tail){
		cout<<"head"<<'|';
		for(int i=head;i<tail;i++){
			cout<<data[i]<<'|';
		}
		cout<<"tail"<<endl;
	}
	else{
		cout<<"head"<<'|';
		for(int i=head;i<30;i++){
			cout<<data[i]<<'|';
		}
		for(int i=0;i<tail;i++){
			cout<<data[i]<<'|';
		}
		cout<<"tail"<<endl;
	}
}
void Queue::append(double item){
	data[tail]=item;
	if(29==tail){
		tail=0;
	}
	else{
		++tail;
	}
	if(tail==head){
		flag1=1;
	}
	else{
		flag1=0;
	}
	flag2=0;
}
void Queue::pop(){
	data[head]=0;
	if(29==head){
		head=0;
	}
	else{
		head++;
	}
	if(head==tail){
		flag2=1;
	}
	else{
		flag2=0;
	}
	flag1=0;
}
bool Queue::isNull(){
	if(flag2)return true;
	return false;
}
bool Queue::isFull(){
	if(flag1)return true;
	return false;
}
