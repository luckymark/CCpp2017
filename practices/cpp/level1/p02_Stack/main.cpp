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
#include "stack.h"

int main(int argc, char** argv) 
{
	Stack stack;
	
	if(stack.isEmpty())
	{
		puts("Status: Empty");
	} 
	if(stack.isFull())
	{
		puts("Status: Full");
	}
	stack.append(1);
	stack.pop();
	
	return 0;
} 
