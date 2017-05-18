#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue():i(0)
{
    //ctor
}

Queue::~Queue()
{
    //dtor
}

void Queue::append(int number)
{
    data[i]=number;
    i++;
    if(i==100)i=0;
}

void Queue::pop()
{
    for(int j = 0 ; j < 100 ; j++){
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
    if(i == 100)return true;
    return false;
}













