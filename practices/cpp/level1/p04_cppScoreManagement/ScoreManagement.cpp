#include "ScoreManagement.h"
#include <iostream>
using namespace std;


void ScoreManagement::ShowSelectionList()
{
	cout << "1.查看学生名单（含所有信息）" << endl;
	cout << "2.选课（添加学生）" << endl;
	cout << "3.退选（删除学生）" << endl;
	cout << "4.录入成绩（从特定学号开始，每录入完一人，询问是否继续）" << endl;
	cout << "5.退出程序" << endl;

}

void ScoreManagement::Select(struct StudentIdentifies a[quantity],int option)
{

	switch (option)
	{
	case 1:
		Show(a);
		break;
	case 2:
		Add(a);
		break;
	case 3:
		Delete(a);
		break;
	case 4:
		Insert(a);
		break;
	case 5:
		exit(0);
	}
}

void ScoreManagement::Show(StudentIdentifies a[quantity])
{
	cout << "所有的学生及其信息如下：" << endl;
	for (int i = 0; i < quantity; ++i)
	{
		if (a[i].name != "")
		{
			cout << a[i].name << endl;

		}
		if (a[i].stID != 0)
		{
			cout << a[i].stID << endl;

		}
		if (a[i].score != 0)
		{
			cout << a[i].score << endl;

		}
	}
}

void ScoreManagement::Add(StudentIdentifies a[quantity])
{	
	cout << "您要添加的学生是:" << endl;	
	cin >> a[Count].name;
	cout << "其学号为:" << endl;
	cin >> a[Count].stID;
	Count += 1;
}

void ScoreManagement::Delete(StudentIdentifies a[quantity])
{
	int i = 0;
	cout << "您想要删除学生学号为：" << endl;
	cin >> a[i].stID;
	a[i].name = "";
	a[i].stID = 0;
	a[i].score = 0;

}

void ScoreManagement::Insert(StudentIdentifies a[quantity])
{
	int i = 0;
	cout << "您想要录入成绩的学生学号为：" << endl;
	cin >> a[i].stID;
	cout << "该学生的成绩为:" << endl;
	cin >> a[i].score;
}
