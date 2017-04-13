#include "SafeArray.h"
#include <iostream>
using namespace std;

void SafeArray::put(int number, int value)
{
	if(number>=k)
	{
		cout<<"Sorry the array is full."<<endl;
	}
	else
	{
		array[number]=value;
	}
}

int SafeArray::get(int number)
{
	if(number>=k)
	{
		cout<<"Ilegal visit."<<endl;
		return 0;	
	}
	else
	{
		return array[number];
	}
}
