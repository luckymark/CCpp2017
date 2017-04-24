#include <iostream>
#include "Stack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	Stack stack;
	stack.sizable(100);
	printf("isFull=%d\n",stack.isFull());
	printf("isEmpty=%d\n",stack.isEmpty());
	for (int i=0;i<100;i++){
		stack.push(i);
	}
	printf("isFull=%d\n",stack.isFull());
	printf("isEmpty=%d\n",stack.isEmpty());
	for (int i=0;i<100;i++){
		stack.pop();
	}
	printf("isFull=%d\n",stack.isFull());
	printf("isEmpty=%d\n",stack.isEmpty());
	return 0;
}
