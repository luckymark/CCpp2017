#include "Queue.h"
#include <cstring>
#define MN 100
 
Queue::Queue()
{
    head=0;tail=0;
    memset(container,0,sizeof(container));
} 

int Queue::append(int element)
{
	container[head++] = element;
}

int Queue::top()
{
	return container[head];
}
void Queue::pop()
{
	tail++;
}

bool Queue::isFull()
{
    if(head - tail == MN) 
	{
		return true;
	}
    else 
    {
    	return false;
	}		
}

bool Queue::isEmpty()
{
    if(head == tail)
	{
		return true;
	}
    else 
	{
		return false;
	}
}
