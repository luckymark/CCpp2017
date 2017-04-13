#pragma once
class Stack
{
public:
	void append(int data);
	int pop();
	bool isFull();
	bool isEmpty();

protected:
private:
	int data[100];
	int head = 0;
	int tail = 0;
};
