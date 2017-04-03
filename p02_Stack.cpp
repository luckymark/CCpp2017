#include<iostream>
#include"Stack.h"

using namespace std;

void main()
{
	Stack s;

	char ch;

	while (1)
	{
		cin >> ch;
		switch (ch)
		{
		case'p':
			if (!s.IsFull())
			{
				cout << "push: ";
				int tem;
				cin >> tem;
				s.push(tem);
			}
			else cout << "Full";
			break;
		case'o':
			if (!s.IsEmpty())
			{
				s.pop();
			}
			else cout << "Empty";
			break;
		case's':
			if(!s.IsEmpty())
			s.show();
			else cout << "Empty" << endl;
			break;
		}

	}
}