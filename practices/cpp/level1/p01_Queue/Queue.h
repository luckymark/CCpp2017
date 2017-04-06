#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
	public:
		Queue(int size);
		~Queue();
		int getSize();
		void append(int x);
		void pop();
		bool isFull();
		bool isEmpty();
		
	protected:
		int size;
		int *data;
		int head=0;
		int tail=-1;
		int flag=0;

};

#endif
