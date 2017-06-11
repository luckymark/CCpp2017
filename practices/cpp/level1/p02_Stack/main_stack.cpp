#include <iostream>
#include"stack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	stack stack1;
	stack1.push(123);
	if(stack1.isEmpty()==1)
	{
		printf("The stack is empty");
	}
	else
	{
		printf("The stack is not empty");
	}
	return 0;
}
