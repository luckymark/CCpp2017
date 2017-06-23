#include <iostream>

#include "queue.h"



bool Queue::isEmpty()
{
	if(tail == head)
	{
		return true;
	}
	return false;
}

bool Queue::isFull()
{
	if((tail + 1) % 100 == head)
	{
		return true;
	}
	return false;
}

int Queue::append(int x)
{
	if(isFull())
	{
		puts("Error: List is full, appending failed.");
		return -1;
	}
	data[tail++] = x;
	tail = tail % 100;
	return 0;
}
int Queue::pop()
{
	int ans = data[head];
	if(isEmpty())
	{
		puts("Error: List is empty, poping failed.");
		return -1;
	}
	data[head++] = 0;
	head = head % 100;
	return ans;
}	
	
