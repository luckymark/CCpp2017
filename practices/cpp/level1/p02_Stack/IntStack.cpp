#include "IntStack.h"
#include<iostream>
using std::cout;
using std::endl;
IntStack::IntStack(int item){
	len=item;
	int *p=new int[item];
	data=p;
}
void IntStack::disp(){
	cout<<"top\n";
	if(flag){
		cout<<data[top]<<endl;
	}
	for(int i=top-1;i>=0;i--){
		cout<<data[i]<<endl;
	}
	cout<<"bottom\n";
}
void IntStack::push(int item){
	data[top]=item;
	if(top<len-1){
		++top;
	}
	else{
		flag=1;
	}
}
void IntStack::pop(){
	if(len-1==top&&flag){
		flag=0;
		return;
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
