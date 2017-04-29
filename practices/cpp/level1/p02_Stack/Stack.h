#ifndef STACK_H
#define STACK_H

class Stack
{
	public:
		Stack(int n){
			if(n>100){
				n=100;
			}
			length = n;
		}
		bool is_Empty = 1;
		bool is_Full = 0;
		int pop();
		void push(int);
	protected:
		int data[100] = {0};	
		int length;
		int tail = 0;
};

#endif
