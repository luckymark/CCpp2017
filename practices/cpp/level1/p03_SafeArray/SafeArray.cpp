#include "SafeArray.h"
#include <iostream>

int capbility;

SafeArray::SafeArray(int cap)
{
	data = new int [cap + 1];//extra space for saving error data
	capbility = cap;
}

SafeArray::~SafeArray()
{
	delete data;
}

int& SafeArray::operator[] (int n)
{
	if(n >= 0 && n < capbility)
	{
		return data[n];
	}
	else
	{
		printf("Error: Out of limit");
		return data[capbility];
	}
}
