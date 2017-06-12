#include<iostream>
class Queue {

public: 
	void show();
	void append(int num);
    int pop();
	bool isEmpty();
	bool isFull();

private:
	int data[20];
	int head = 0;
	int tail = 0;
};
