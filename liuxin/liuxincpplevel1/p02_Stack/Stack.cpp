#include <cstdlib>
#include <iostream>
#include "Stack.h"

Stack::Stack(int x){
	tot=0;
	element=new int[num=x];
}

Stack::~Stack(){
	delete[] element;
}

void Stack::push(int x){
	if (tot==num) {
		std::cerr<<"Full!!Can't add anymore!\n"<<std::endl;
		return;
	}
	element[tot++]=x;
}

void Stack::pop(){
	tot--;
}

int Stack::top(){
	return element[tot-1];
}

bool Stack::IsFull(){
	return tot==num;
}

bool Stack::IsEmpty(){
	return tot==0;
}

