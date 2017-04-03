#include<iostream>
#include"Stack.h"

using namespace std;

void Stack::push(int item)
{
	this->item[pos] = item;
	pos++;
}

void Stack::pop()
{
	cout << "pop " << item[pos-1]<<endl ;
	pos--;
}

int Stack::IsFull()
{
	return pos == n;
}

int Stack::IsEmpty()
{
	return pos == 0;
}

void Stack::show()
{
	for (int i = 0; i < pos; i++)
		cout << item[i];
	cout << endl;
}

Stack::Stack()	
{
	pos = 0;
}