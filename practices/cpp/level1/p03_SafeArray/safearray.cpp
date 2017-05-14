#include<iostream>
#include "safearray.h"

using namespace std;

safearray::safearray()
{
	data = NULL;
	size = 0;
}

safearray::safearray(int s)
{
	size = s;
	data = new int [size];
}

safearray::~safearray()
{
	delete[] data;
	data = NULL;
	size = 0;
}

int& safearray::operator[](int i)
{
	if(i < 0 || i >= size)
	{
		cout<<"Array index out of range."<<endl;
		return this->data[size];
	}
	return this->data[i];
}
