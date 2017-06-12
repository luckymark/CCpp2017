#include "queue.h"
#include<iostream>
using namespace std;

void Queue::append( int item )
{ 
    data[tail] = item; 
    item ++;
} 

int Queue::pop()
{
	if(Queue::isFull())
	{
		for(int i=100;i>1;i--)
		{
			data[i] = data[i-1];
		}
	}
}

bool Queue::isEmpty()
{
	if(tail == 0)
	{
		cout << "it is empty" <<endl;
		return true;
	}else 
	{
		return false;
	}   
};

bool Queue::isFull()
{
	if(tail == 100)
	return true;
};

void Queue::Show()
{
	for(int i=0;i<100;i++)
	{
		cout << data[i] <<endl;
	}
}
