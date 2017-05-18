#include "Stack.h"

Stack::Stack()
{
    //ctor
}

Stack::~Stack()
{
    //dtor
}

void Stack::append(int number)
{
	container[head++] = number;
}

void Stack::pop()
{
	head--;
}

int Stack::show()
{
	if(head - 1 < 0) return -1;
	else return container[head-1];
}

bool Stack::IsFull()
{
	return head == TOP;
}

bool Stack::IsEmpty()
{
	return head == 0;
}
