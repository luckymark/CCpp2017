#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
	public:
		void disp();
		void append(double item);
		void pop();
		bool isNull();
		bool isFull();
	protected:
	private:
		double data[30]={0};
		int head=0;
		int tail=0;
		bool flag1=0,flag2=1; 
};

#endif
