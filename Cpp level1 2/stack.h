#pragma once
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include "stack.h"
using namespace std;
template <class T>
class Stack
{

private:
	T* st;
	int index = 0;
	int num;
public:

	Stack(int num)
	{
		st = new T[num];
		this->num = num;
	}

	~Stack()
	{
		delete[]st;
	}

	void push();
	void pop();
	void show();
	bool isEmpty();
	bool isFull();
};


template <class T>
void Stack<T>::pop()
{
	if (!isEmpty())
	{
		index--;
		while (getchar() != '\n')
		{
			continue;
		}
	}
	else
	{
		printf("the stack is empty");
	}
}

template <class T>
void Stack<T>::push()
{
	if (!isFull())
	{

		cin >> st[index];
		index++;
		while (getchar() != '\n')
		{
			continue;
		}
	}
	else
	{
		printf("the stack is full\n");
	}
}


template <class T>
bool Stack<T>::isEmpty()
{
	if (index == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
bool Stack<T>::isFull()
{
	if (index >= num)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
void Stack<T>::show()
{
	for (int i = 0; i < index; i++)
	{
		cout << st[i] << " ";
	}
}