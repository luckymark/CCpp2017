#include "safearray.h"
#include <iostream>
#include <string.h>

using namespace std;

SafeArray::SafeArray(int top)
{
	data=new int[top];
	Max=top;
	memset(data,0,top);
}
SafeArray::~SafeArray()
{
	delete []data;
	data=NULL;
}
void SafeArray::write(int index,int x)
{
	if(index<0||index>=Max)
	{
		cout<<"error in write!";
	}
	data[index]=x;
}
int SafeArray::read(int index)
{
	if(index<0||index>=Max)
	{
		cout<<"error in read!";
		return 0;
	}
	return data[index];
}
