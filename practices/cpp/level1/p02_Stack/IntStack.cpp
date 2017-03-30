#include "IntStack.h"
#include<iostream>
using std::cout;
using std::endl;
void IntStack::disp(){
	cout<<"top\n";
	for(int i=top-1;i>=0;i--){
		cout<<data[i]<<endl;
	}
	cout<<"bottom\n";
}
void IntStack::push(int item){
	data[top]=item;
	if(top<99){
		++top;
	}
	else{
		flag=1;
	}
}
void IntStack::pop(){
	if(99==top){
		flag=0;
	}
	--top;
}
bool IntStack::isFull(){
	if(flag)return true;
	return false;
}
bool IntStack::isNull(){
	if(0==top)return true;
	return false;
}
