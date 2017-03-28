#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
	public:
		void disp();
		void initialize();
		void append(double item);
		void pop();
		bool isNull();
		bool isFull();
	protected:
	private:
		double data[30];
		int head;
		int tail;
};

#endif
