
#include "stdafx.h"
#include "Queue_.h"
using namespace std;
int main()
{
	Queue_ line;
	line.one_first();
	char ch;
	while (1)
	{
		cout << "please choose mode!" << endl;
		ch = cin.get();
		cin.clear();
		switch (ch)
		{
		case '1':
			line.one_append();
			break;
		case '2':
			line.one_pop();
			cin.get();
			break;
		default:
			break;
		}
		cin.get();
		system("cls");
	}


    return 0;
}

