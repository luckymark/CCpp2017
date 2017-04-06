#include <cstdlib>
#include "Stack.h"

Stack::Stack(int x){
	tot=0;
	element=(int *)malloc(sizeof(int)*x); 
}

Stack::~Stack(){
	free(element);
}

void Stack::push(int x){
	element[tot++]=x;
}

void Stack::pop(){
	tot--;
}

int Stack::top(){
	return element[tot-1];
}

bool Stack::IsFull(){
	return tot==MAXSTACK;
}

bool Stack::IsEmpty(){
	return tot==0;
}

