#include "Queue.h"

bool Queue::isFull() {
	if (head==(tail+1)%100)
	return true;
	else return false;
}

void Queue::append(int item)
{
	data[tail] = item;
	tail=(tail+1)%100;
}

int  Queue::pop(void)
{
	int temp = data[head];
	head = (head + 1) % 100;
	return data[head];
}
bool Queue::isEmpty(void)
{
	if (head == tail)return true;
	else return false;
}
