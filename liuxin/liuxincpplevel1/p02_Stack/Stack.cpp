#include <cstdlib>
#include "Stack.h"

Stack::Stack(int x){
	tot=0;
	a=(int *)malloc(sizeof(int)*x); 
}

Stack::~Stack(){
	free(a);
}

void Stack::push(int x){
	a[tot++]=x;
}

void Stack::pop(){
	tot--;
}

int Stack::top(){
	return a[tot-1];
}

bool Stack::IsFull(){
	return tot==MAXSTACK;
}

bool Stack::IsEmpty(){
	return tot==0;
}

