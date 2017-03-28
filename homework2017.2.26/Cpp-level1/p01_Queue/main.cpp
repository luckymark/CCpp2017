#include <iostream>
#include "Queue.h" 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	Queue queue;
	printf("length=%d\n",queue.length);
	printf("isFull=%d\n",queue.isFull());
	printf("isEmpty=%d\n\n",queue.isEmpty());
	
	for (int i=1;i<=100;i++){
		queue.appand(i);
	}
	printf("length=%d\n",queue.length);
	printf("isFull=%d\n",queue.isFull());
	printf("isEmpty=%d\n\n",queue.isEmpty());
	
	queue.pop();
	printf("length=%d\n",queue.length);
	printf("isFull=%d\n",queue.isFull());
	printf("isEmpty=%d\n",queue.isEmpty());
	
	return 0;
}
