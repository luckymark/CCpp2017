#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
public:
	bool isFull();
	void append(int data);
	int pop(void);
	bool isEmpty(void);
	int data[100];
	int head = 0;
	int tail = 0;
protected:
private:
};
#endif