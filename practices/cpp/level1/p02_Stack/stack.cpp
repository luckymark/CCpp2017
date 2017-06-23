#include <stdio.h>

#include "stack.h"



bool Stack::isEmpty()
{
	if(tail == head)
	{
		return true;
	}
	return false;
}

bool Stack::isFull()
{
	if((tail == 100)
	{
		return true;
	}
	return false;
}

int Stack::append(int x)
{
	if(isFull())
	{
		puts("Error: List is full, appending failed.");
		return -1;
	}
	data[tail++] = x;
	return 0;
}

int Stack::pop()
{
	if(isEmpty())
	{
		puts("Error: List is empty, poping failed.");
		return -1;
	}
	int ans = data[--tail];
	data[tail] = 0;
	return ans;
}	
	
