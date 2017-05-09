#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(int size)
{
	this->size=size;
	data=new int[size];
	head=0;
	tail=0;
}

Queue::~Queue()
{
	delete[] data;
}

bool Queue::isEmpty()
{
	return flag ==0;
}

bool Queue::isFull()
{
	return flag==size;
} 



void Queue::append(int x)
{
	if(isFull())
	{
		cout<<"Append failed£¡The Queue is full!"<<endl;
		return ;
	}
	tail= tail==size-1? 0:tail+1;
	data[tail]=x;
	flag++;
	
}
 
void Queue::pop()
{
	if(isEmpty())
	{
		cout<<"Pop failed! The Queue is empty!"<<endl;
		return ;
	}
	data[head]=0;
	head++;
	flag--;
}
