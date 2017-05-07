#include<iostream>
#include "safearray.h"

using namespace std;

int main(void)
{
	safearray array(5);
	for(int i = 0; i < 5; i++)
	{
		array[i] = i;
	}
	for(int i = 0; i < 5; i++)
	{
		cout<<(array[i])<<" ";
	}
	cout<<endl;
	array[5] = 1;
	return 0;
}
