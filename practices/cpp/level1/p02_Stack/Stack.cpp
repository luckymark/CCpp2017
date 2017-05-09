#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack(int size)
{
	this->size=size;
	data=new int[size];	
}

Stack::~Stack()
{
	delete[] data;
}

bool Stack::isEmpty()
{
	return tail==-1;
}

bool Stack::isFull()
{
	return tail==size-1;
}

int Stack::getSize()
{
	return size;
}

void Stack::append(int x)
{
	if(isFull())
	{
		cout<<"Stack is full!"<<endl;
		return ;
	}
	tail++;
	data[tail]=x;
}

void Stack::pop()
{
	if(isEmpty())
	{
		cout<<"Stack is empty!"<<endl;
	}
	data[tail]=0;
	tail--;
}
