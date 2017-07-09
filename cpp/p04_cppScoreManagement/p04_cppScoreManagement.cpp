#include<iostream>
#include"Stu.h"



using namespace std;

void main()
{
	FILE* pt;
	if (fopen_s(&pt, "info.txt", "r") != 0)
		cout << "can not open file." << endl;

	Queue pq;

	pq.load(pt);
	fclose(pt);

	pq.menu();
	char ch;
	cin >> ch;
	while (cin.get() != '\n');


	char name[11]; 

	while (ch != 'q')
	{

		switch (ch)
		{
		case'a':
			pq.AddStu();
			break;
		case'd':
			cout << "name:";
			cin >> name;
			pq.DelStu(name);
			break;
		case'l':
			pq.list();
			break;
		case'f':
			cout << "name:";
			cin >> name;
			pq.find(name);
			break;
		case'c':
			pq.ChangeInfo();
			break;
		case's':
			pq.sort();
		}
		pq.menu();
		cin >> ch;
		while (cin.get() != '\n');
	}

	if (fopen_s(&pt, "info.txt", "w") != 0)
		cout << "can not save info." << endl;
	pq.save(pt);
	fclose(pt);

	getchar();
}
