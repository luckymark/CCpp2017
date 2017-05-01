#include "Queue.h"
#include <iostream>
using namespace std;
void Queue::disp(void) {
	cout << "The queue is as follows:" << endl;
	for (int i = head;i < tail;++i) {
		cout << data[i] << endl;
	}
}
void Queue::append(int num){
	data[tail] = num;
	tail = (tail + 1) % 100;
}

int Queue::pop(void) {
	int temp = data[head];
	head = (head + 1) % 100;
	return temp;
}

bool Queue::isFull(void) {
	if (head == (tail + 1) % 100)
		return true;
	else
		return false;
}

bool Queue::isEmpty(void) {
	if (head == tail)
		return true;
	else
		return false;
}