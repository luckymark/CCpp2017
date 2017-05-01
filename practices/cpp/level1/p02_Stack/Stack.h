#ifndef STACK_H
#define STACK_H
#include <stdbool.h>
class Stack
{
public:
	bool isFull();
    void push(int data);
	int pop();
	bool isEmpty();
	int data[100];
	int top = 0;
protected:
private:
};
#endif