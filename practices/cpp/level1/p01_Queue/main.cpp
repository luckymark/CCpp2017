#include<iostream>
#include"Queue.h"
int main()
{
	Queue queue;
	if (!queue.isFull()) {
		queue.append(100);
	}
	for (int i = queue.head; i != queue.tail; i = (i + 1) % 100) {
		printf("%d", queue.data[i]);
	}
}