#ifndef STACK_H
#define STACK_H
#define MAXDATA 100

class stack
{
	public:
		void push(int temp);
		void pop();
		bool isFull();
		bool isEmpty();
	private:
		int data[100]={0};
		int tail=0;
		int head=0;
};

#endif
