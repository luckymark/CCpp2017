#ifndef QUEUE_H_
#define QUEUE_H_

class Queue
{
	public:
		bool full();
		bool empty();
		void append(int data);
		void pop(int data);
		void display();
	private:
		int data[100];
		int head = 0;
		int tail = 0;
};

#endif /* QUEUE_H_ */
