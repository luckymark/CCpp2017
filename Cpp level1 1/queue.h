#pragma once
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
//逻辑上的始终，不必是物理上的始终
using namespace std;
template <class T>
class Queue
{

private:
	T* qu;
	int tail = 0;
	int num;
	int head = 0;
	int mark = 0;
	int flag = 0;
public:

	Queue(int num)
	{
		qu = new T[num];
		this->num = num;
	}

	~Queue()
	{
		delete[]qu;
	}

	void append();
	void pop();
	void show();
	bool isEmpty();
	bool isFull();
	bool judge(int i);
};


template <class T>
void Queue<T>::pop()
{
	if (!isEmpty())
	{
		head=(head+1)%num;
		while (getchar() != '\n')
		{
			continue;
		}
		mark = 0;
	}
	else
	{
		printf("the queue is empty");
	}
}

template <class T>
void Queue<T>::append()
{
	if (!isFull())
	{

		cin >> qu[tail];
		tail = (tail + 1) % num;
		while (getchar() != '\n')
		{
			continue;
		}
		mark = 1;
	}
	else
	{
		printf("the queue is full\n");
	}
}


template <class T>
bool Queue<T>::isEmpty()
{
	if (tail == head&&mark == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
bool Queue<T>::isFull()
{
	if (tail ==head&&mark==1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
void Queue<T>::show()
{
	for (int i = head;judge(i); i=(i+1)%num,flag=1)
	{
		cout << qu[i] << " ";
	}
	flag = 0;
}

template <class T>
bool Queue<T>::judge(int i)
{
	if (i == tail&&isFull() && flag == 0||i!=tail)
	{
		return true;
	}
	else
	{
		return false;
	}
}