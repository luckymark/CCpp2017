#ifndef STACK_H_
#define STACK_H_

#define n 100

class Stack
{
private:
	int item[n];
	int pos ;
public:
	void push(int item);
	void pop();
	int IsFull();
	int IsEmpty();
	void show();
	Stack();
};

#endif