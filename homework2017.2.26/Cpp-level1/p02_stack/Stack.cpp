#include "Stack.h"
#include <cstring>
#include <cstdlib>
#include <cstdio>

Stack::Stack(){
	head=-1;
	data=NULL;
	length=0;
}

void Stack::sizable(int len){
	length=len;
	data=(int*)malloc(length*sizeof(int));
}

void Stack::pop(){
	head--;
}

void Stack::push(int item){
	if (head==length-1){
		printf("The stack is Full\n");
		return;
	}
	data[++head]=item;
}

bool Stack::isFull(){
	return head==length-1;
}

bool Stack::isEmpty(){
	return !(head+1);
}


