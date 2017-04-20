#ifndef STACK_H
#define STACK_H

class Stack
{
	private:
		
		int *container;
		
		int head = 0;
		
		int STACK_TOP = 100;	
			
	public:
		
		Stack();
		
		Stack(int size);
		
		~Stack();
		
		void Push(int value);
		
		void Pop();
		
		int Top();
		
		bool IsFull();
		
		bool IsEmpty();
		
};

#endif 
