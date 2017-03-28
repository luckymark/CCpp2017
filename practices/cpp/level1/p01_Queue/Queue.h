/*
 * Queue.h
 *
 *  Created on: 2017年3月28日
 *      Author: mark
 */

#ifndef QUEUE_H_
#define QUEUE_H_

class Queue {
public:
	Queue();

	void append(int number);

	bool IsFull();

	bool Isemp();

	void show();

	virtual ~Queue();

private:

	int data[100];

	int head  ;

	int tail  ;

};

#endif /* QUEUE_H_ */
