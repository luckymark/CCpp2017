// queue.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Queue.h"

int main()
{
	Queue queue;

	if (!queue.isFull())
	{
		queue.append(100);
	}

	int n;
	if (!queue.isEmpty())
	{
		n = queue.pop();
	}

	Queue *p = new Queue();
	p->append(100);
	p = &queue;
    return 0;
}
