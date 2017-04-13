// Stack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"stack.h"
#include<iostream>

using namespace std;

int main()
{
	Stack stack;
	
	int n;
	cout<<"please enter a number you want to set for the array"<<endl;
	cin>>n;
	 

	if (!stack.isFull())
	{
		stack.append(100);
	}

	int o;
	if (!stack.isEmpty())
	{
		o = stack.pop();
	}

	Stack *p = new Stack();
	p->append(100);
	p = &stack;
    return 0;
}

