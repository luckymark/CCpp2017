#ifndef STACK_H
#define STACK_H
class Stack {
public:
	void push(int x);
	int pop();
	bool isEmpty();
	bool isFull();
	int top = 0;
	int stack1[100];
};
#endif