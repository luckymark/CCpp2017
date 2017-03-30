#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

//#define MAX_SIZE 100
class Stack{
		private:
				int *w;
				int top;
				int size;
		public:
				Stack(int _size = 100);
				void push(int x);
				int pop();
				bool is_full();
				bool is_empty();
				~Stack();
};
#endif
