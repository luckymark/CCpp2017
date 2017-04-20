#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
	private:
		int head,tail,container[1000];
	public:
		Queue();
		int append(int element);
		int top();
		void pop();
		bool isFull();
		bool isEmpty();		
};

#endif QUEUE_H
