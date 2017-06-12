#include "queue.h" 
#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Queue queue;
	int data[100];	
	int i=0;
	while(1)
	{
		queue.isEmpty();
		cout <<"please input the numbers";
		cin >> data[i]; 
		if(!queue.isFull())
		{
			i++;
		}
		if(queue.isFull())
		{
			queue.append(data[i]);
		}
		queue.Show();
	}

	return 0;
}

