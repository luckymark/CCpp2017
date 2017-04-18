#include<iostream>
#include"SafeArray.h"

using namespace std;

void Array::visit(int pos, int& visitor)
{
	if (pos > len)
		cout << "over edge" << endl;
	else
		visitor = *(pt + pos);
};

void Array::change(int pos, int value)
{
	if (pos > len)
		cout << "over edge" << endl;
	else
		*(pt + pos) = value;
}
