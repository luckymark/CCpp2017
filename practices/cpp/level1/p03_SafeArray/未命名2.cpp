#include<iostream>
#include<string>
#include"SafeArray.cpp"

using namespace std;
int main(void)
{
	system("chcp 437");
	system("cls");
	SafeArray<int> sa;//���Խ�int���������ľ��������޹ص�������
	cout << "please choose mode!" << endl;
	cout << "a.input    b.pop" << endl;
	char ch;
	int x;
	do
	{
		cin >> ch;
	}
	while (ch != 'a'&&ch != 'b'); 
	system("cls");
	switch (ch)
	{
		case 'a':
		{
			cout << "which elem do u want  to change?" << endl;
			cin >> x;
			cout << "ok,what?" << endl;
			break;
		}
		case 'b':
		{
			//�Ƴ��ܼ�
			break;
		}
		default:
		{
			cout << "bad" << endl;
			system("cls");
		}
	}

	return 0;
}
