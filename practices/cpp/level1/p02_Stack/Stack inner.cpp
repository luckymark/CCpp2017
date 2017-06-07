#include"stack.h"

void Stack::append(int item)
{
	data[head] = item;
	head = (head + 1) % 100;
}

int Stack::pop()
{
	tail = (tail + 1) % 100;
	return data[tail - 1];
}

bool Stack::isEmpty()
{
	return (head == tail);
}

bool Stack::isFull()
{
	return ((head + 1) % 100 = tail);
}