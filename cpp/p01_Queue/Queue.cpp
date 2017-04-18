#include<iostream>
#include"Queue.h"
#define WIDTH 100

using namespace std;

void Queue::append(int item)
{


	rear++;
	if (rear == WIDTH + 1) rear = 0;
	this->item[rear] = item;




}
void Queue::pop()
{
	cout << item[front + 1] << "pop" << endl;

	front++;
	if (front == WIDTH + 1) front = 0;



}

int Queue::IsFull()
{
	int temp;
	rear == WIDTH ? temp = -1 : temp = rear;
	return (temp + 1) == front;
}

int Queue::IsEmpty()
{
	return rear == front;
}

void Queue::show()
{
	for (int i = front + 1; i != rear + 1; i++)	//i为当前访问的item
	{
		if (i > WIDTH) i = 0;	//处理front在数组尾情况，此时i不对应item，将i设为0指向数组首端

		cout << item[i];

		if (i == WIDTH && rear != WIDTH)		//处理rear在数组尾情况
			i = -1;

	}
}