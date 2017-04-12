#ifndef INTSTACK_H
#define INTSTACK_H

class IntStack
{
	private:
		int *data;
		int top=0;
		bool flag=0;
		int len;
	public:
		IntStack(int item=100);
		bool isFull();
		bool isNull();
		void disp();
		void push(int item);
		void pop();
	protected:
};

#endif
