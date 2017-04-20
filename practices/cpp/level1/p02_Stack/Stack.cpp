#include "Stack.h"

Stack::Stack()
{
	container = new int[STACK_TOP];
}

Stack::Stack(int size)
{
	container = new int[size];
}

Stack::~Stack()
{
	delete[] container;
}

void Stack::Push(int value)
{
	container[head++] = value;
}

void Stack::Pop()
{
	head--;
}

int Stack::Top()
{
	if(head - 1 < 0) return -1;
	else return container[head-1];
}

bool Stack::IsFull()
{
	return head == STACK_TOP;
}

bool Stack::IsEmpty()
{
	return head == 0;
}
