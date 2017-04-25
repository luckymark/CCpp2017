#include"scoreManagerment.h"

int main(void)
{
	using namespace std;
	Scoremanage a;
	char ch;
	int count = 1;
	a.show();
	for (int i = 0; i < 3; i++)
	{
		a.add();
	}
	a.show();

	a.del(2);
	a.show();
	cout << "enter student's name(q to quit): ";
	cin >> ch;
	while (ch != 'q')
	{
		
		a.setgrade(count);
		count++;
		cout << "enter student's name(q to quit): ";
		cin >> ch;
	}
	a.show();
	system("pause");
	return 0;
}