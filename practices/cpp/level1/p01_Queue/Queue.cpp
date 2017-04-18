#include "queue.h"
#include <iostream>

using namespace std;

queue::queue():i(0)
{
    //ctor
}

queue::~queue()
{
    //dtor
}

void queue::append(int number)
{
    data[i]=number;
    i++;
    if(i==10)i=0;
}

void queue::pop()
{
    for(int j = 0 ; j < 10 ; j++){
		cout << data[j] <<endl;
	}

}

bool queue::IsEmpty()
{
    if(i == 0)
    {
        cout<<"it is empty!"<<endl;
        return true;
    }
    return false;
}

bool queue::IsFull()
{
    if(i == 10)return true;
    return false;
}













