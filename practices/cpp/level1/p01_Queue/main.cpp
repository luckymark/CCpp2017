/*
 * Author:	Kyrios0
 * Date:	2016.04
 * To-Do List:
 * 			~~isEmpty~~
 *			~~isFull~~
 * 			~~append~~ 
 * 			~~pop~~ 
 *			~~Optimization~~
 * 			and more?
 * State:	Completed
 */
#include <iostream>
#include "queue.h"

int main(int argc, char** argv) 
{
	Queue queue;
	
	if(queue.isEmpty())
	{
		puts("Status: Empty");
	} 
	if(queue.isFull())
	{
		puts("Status: Full");
	}
	queue.append(1);
	queue.pop();
	
	return 0;
} 
