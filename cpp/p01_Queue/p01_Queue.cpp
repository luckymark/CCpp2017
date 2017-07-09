#include <iostream>
#include <string>
#include"Queue.h"

#define WIDTH 100

using namespace std;


int main() 
{
	Queue queue;

	char ch;
	int item;
	while (1)
	{
		
		cin >> ch;
		switch (ch)
		{
		case'a':
			if (!queue.IsFull())
			{ 
				cout << "add:";
				cin >> item;
				queue.append(item);
			}
			else cout << "full" << endl;
			break;
		case'p':
			if (!queue.IsEmpty())
			{
				queue.pop();
				cout << endl;
			}
			else cout << "empty" << endl;
			break;
		case's':
			queue.show();
			cout << endl;
		}
	}
	return 0;
}

