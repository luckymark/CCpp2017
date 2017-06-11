#include "Queue.h"
bool Queue::isFull()
{
	if(data[100]!=0)
	{
		return true;
	}
	else
	return false;
}
bool Quene::isEmpty()
{
	return data==tail;
} 
void Queue::append(int item)
{
	if ((tail+1)%100==head) 
	{
		cout<<"Full!\n";
		return;
	}
	tail++;
	if (tail==MAXQUEUE)
	tail=0;
	data[tail]=item;
}
void Queue::pop()
{
	if (head!=tail) 
	{
		head++;
		if (head==MAXQUEUE) 
			head=0;
	}
}
