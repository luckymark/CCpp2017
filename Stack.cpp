#include "Stack.h"

int Stack::pop(){
	return s[--p];
}

bool Stack::push(int x){
	if(p<capability){
		s[p++]=x;
		return 1;
	}
	else{
		return 0;
	}
}

bool Stack::isEmpty(){
	return p==0;
}

bool Stack::isFull(){
	return p==capability;
}

void Stack::clear(){
	while(p){
		pop();
	}
}
