#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
	public:
		bool is_Full = 0;
		bool is_Empty = 1;
		void append(int);
		int pop();
	protected:
		int head = 0;
		int tail = 0;
		int data[100] = {0};
};

#endif
