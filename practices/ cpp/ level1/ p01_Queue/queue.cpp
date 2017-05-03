#include<iostream>
using namespace std;

class Queue {
private:
	int num[100];
	int app_num;
	int pop_num;
	int *p;
public:
	Queue();
	void append();
	void pop();
	bool if_full();
	bool if_empty();
};

Queue::Queue()
{
	num[100] = { 0 };
	app_num = 0;
	pop_num = 0;
	p = num;
}
void Queue::append()
{
	for (int i = 0; i < 100; i++) {
		num[i] = i;
		app_num++;
		cout << num[i]<<"\t";
	}
}

void Queue::pop()
{
	for (int i = 1; i < 101; i++) {
		p++;
		pop_num++;
	}
}

bool Queue::if_full()
{
	if (app_num == 100) {
		return true;
	}
	else {
		return false;
	}
}

bool Queue::if_empty()
{
	if (pop_num == 100||app_num==0) {
		return true;
	}
	else {
		return false;
	}
}

Queue queue;
void main()
{
	if (queue.if_empty()){
		cout << "The queue is now empty." << endl;
	}
		queue.append();
		cout << "\n";
	if (queue.if_full()) {
		cout << "The queue is now full." << endl;
		queue.pop();
	if (queue.if_empty()){
		cout << "The queue is now empty." << endl;
		}
	}
}
