#ifndef STACK_H
#define STACK_H

class Stack
{
	public:
		Stack(int size);
		~Stack();
		bool isEmpty();
		bool isFull();
		void append(int x);
		void pop();
		int getSize();
	protected:
		int size;
		int *data;
		int tail=-1;
};

#endif
