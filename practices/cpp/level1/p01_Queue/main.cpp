#include <iostream>
#include "Queue.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	Queue queue(2);
	cout<<queue.isEmpty()<<endl;
	cout<<queue.isFull()<<endl;
	
	queue.append(2);
	queue.append(2);
	cout<<queue.isEmpty()<<endl;
	cout<<queue.isFull()<<endl;
	queue.append(2);
	
	queue.pop();
	queue.pop();
	cout<<queue.isEmpty()<<endl;
	cout<<queue.isFull()<<endl;
	queue.pop();
	return 0;
}
