#include"Queue.h"

using namespace std;
void Queue::show() {
	cout << "Here are the datas in the queue:";

	for (int i = head;(i % 20 + 1) <= tail;i++) {
		cout << data[i]<<"  ";
	}
}

void Queue::append(int num) {
	data[tail] = num;
	tail = (tail + 1) % 20;
}

int Queue::pop() {
	head = (head + 1) % 20;
	return data[head];
}

bool Queue::isEmpty() {
	return(head == tail);
}

bool Queue::isFull() {
	return((tail + 1) == head);
}