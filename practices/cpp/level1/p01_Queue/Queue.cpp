#include "Queue.h"
#include <iostream>

using namespace std;

Queue::queue():i(0)
{
    //ctor
}

Queue::~queue()
{
    //dtor
}

void Queue::append(int number)
{
    data[i]=number;
    i++;
    if(i==10)i=0;
}

void Queue::pop()
{
    for(int j = 0 ; j < 10 ; j++){
		cout << data[j] <<endl;
	}

}

bool Queue::IsEmpty()
{
    if(i == 0)
    {
        cout<<"it is empty!"<<endl;
        return true;
    }
    return false;
}

bool Queue::IsFull()
{
    if(i == 10)return true;
    return false;
}













