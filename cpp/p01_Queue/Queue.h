#ifndef Queue_H_
#define Queue_H_

#define WIDTH 100

class Queue
{
private:
	int item[WIDTH + 1];
	int front = 0;		//front+1是队列首元
	int rear = 0;

public:
	void append(int item);
	void pop();
	int IsFull();
	int IsEmpty();
	void show();
};

#endif