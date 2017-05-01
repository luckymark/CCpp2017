#include "stack.h"
void stack::push(int temp)
{
	data[tail]=temp;
	tail++;
}
void stack::pop()
{
	tail--;
}
bool stack::isFull()
{
	if(data[MAXDATA]!=0)
	{
		return true;
	}
		return false;
}
bool stack::isEmpty()
{
	if(data[0]==0)
	{
		return true;
	}
	return false;
}
