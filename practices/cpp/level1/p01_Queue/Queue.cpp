#include "Queue.h"
#include<iostream>
using namespace std;
void Queue::initialize(){
	head=tail=0;
	for(int i=0;i<30;i++){
		data[i]=0;
	}
}
void Queue::disp(){
	if(head<tail){
		cout<<'|';
		for(int i=head;i<tail;i++){
			cout<<data[i]<<'|';
		}
		cout<<endl;
	}
	else{
		cout<<'|';
		for(int i=head;i<30;i++){
			cout<<data[i]<<'|';
		}
		for(int i=0;i<tail;i++){
			cout<<data[i]<<'|';
		}
		cout<<endl;
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
}
void Queue::pop(){
	data[head]=0;
	if(29==head){
		head=0;
	}
	else{
		head++;
	}
}
bool Queue::isNull(){
	if(0==data[head])return true;
	return false;
}
bool Queue::isFull(){
	if(data[tail]!=0)return true;
	return false;
}
