#include<iostream> 
#include "Queue.h"

using namespace std;

bool Queue::full()
{
    if(tail == 100)
	   return true;
	else
	   return false;
}

bool Queue::empty()
{
    if(tail == 0)
	   return true;
	else
	   return false;
}

void Queue::append(int item)
{
	data[tail] = item;
	tail++;
}

void Queue::pop(int item)
{
	data[item] = 0;
	tail--;
}

void Queue::display()
{
    for(int i = 0; i < 100; i++)
    {
        cout << data[i] <<" ";
    }
}
