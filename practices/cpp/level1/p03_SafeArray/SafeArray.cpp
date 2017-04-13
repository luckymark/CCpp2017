#include "SafeArray.h"

safearray::safearray(void)
{
	num = 0;
	arr = NULL;
}

safearray::safearray(int n)
{
	num = n;
	arr = new int[n];
	for(int i=0;i<n;++i)
	{
		arr[i] = 0;
	}
}

safearray::safearray(const safearray & a)
{
	num = a.num;
	arr = new int[num];
	for (int i = 0; i < num; ++i)
	{
		arr[i] = a.arr[i];
	}
}

safearray::~safearray(void)
{
	delete[]arr;
}

int& safearray::operator[](int n)
{
	if (n>=num) 
	{
		std::cout << "error" << std::endl;
		int a;
		return a;
	}
	else
	{
		return arr[n];
	}
		
}

safearray & safearray::operator=(const safearray & a)
{
	delete arr;
	num = a.num;
	arr = new int[num];
	for (int i = 0; i < num; ++i)
	{
		arr[i] = a.arr[i];
	}
	return *this;
	// TODO: insert return statement here
}

