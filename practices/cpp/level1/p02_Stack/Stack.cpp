#include "Stack.h"
#include <iostream>
using namespace std;

void Stack::push(int num){
	if(!is_Full){
		data[tail] = num;
		tail++;
		if(is_Empty){
			is_Empty = 0;
		}
		if(tail >= length){
			is_Full = 1;
		}
	}
	else{
		cout<<"PUSH ERROR 001"<<endl;
	}
}

int Stack::pop(){
	if(!is_Empty){
		tail--;
		if(is_Full){
			is_Full = 0;
		}
		if(tail == 0){
			is_Empty = 1;
		}
		return data[tail];
	}
	else{
		cout<<"POP ERROR 001 RETURN -23333333"<<endl;
		return -23333333;
	}
}
