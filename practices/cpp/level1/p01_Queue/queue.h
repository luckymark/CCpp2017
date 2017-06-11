#ifndef Queue_H
#define Queue_H

class Queue
{
	public:
		bool isFull();
		void append(int item);
		bool isEmpty();
	protected:
	private:
		int tail=0;
		int head=0;
		int data[100]={0};
};

#endif
