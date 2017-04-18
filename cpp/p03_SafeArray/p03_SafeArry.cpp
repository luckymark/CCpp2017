#include<iostream>
#include"SafeArray.h"

using namespace std;


void main()
{
	int pos, value;

	cout << "len of array:";
	cin >> pos;
	Array array(pos);
	
	char ch;
	
	while (1)
	{
		cout << "v to visit, c to change:" << endl;

		cin >> ch;
		switch (ch)
		{
		case'v':
			cout << "pos in array:" << endl;
			cin >> pos;
			array.visit(pos,value);
			cout <<"the value is:"<<value << endl;
			break;
		case'c':
			cout << "pos to change:" << endl;
			cin >> pos;
			cout << "value to change:" << endl;
			cin >> value;
			array.change(pos, value);
			break;
		}

		cout << endl;
	}
	


	system("pause");
}