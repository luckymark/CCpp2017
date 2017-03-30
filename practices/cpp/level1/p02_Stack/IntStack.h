#ifndef INTSTACK_H
#define INTSTACK_H

class IntStack
{
	private:
		int data[100]={0};
		int top=0;
		bool flag=0;
	public:
		bool isFull();
		bool isNull();
		void disp();
		void push(int item);
		void pop();
	protected:
};

#endif
