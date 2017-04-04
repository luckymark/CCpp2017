#include<iostream>

class Stack {

public:
	void show();
	void append(int num);
	int pop();
	bool isFull();
	bool isEmpty();

private:
	int data[100];
	int cur = 0;
};