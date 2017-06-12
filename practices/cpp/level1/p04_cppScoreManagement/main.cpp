#include<iostream>
#include"cppScoreManagement.h"
#include<windows.h>

/*todolist:
1.对学生操作应当以班级为单位
2.对成绩操作应当通过学生
*/
Class cpp;

void main()
{
	while (1) {
		system("cls");
		cout << "1、查看学生名单\t2、选课\t3、退课\t4、录入成绩\t5、查看已录入学生成绩\t6、退出" << endl;
		int n;
		cin >> n;
		switch (n) {
		case 1:
			cpp.display2();
			system("pause");
			break;
		case 2: {
			string str;
			cout << "请输入您的姓名:" << endl;
			cin >> str;
			cpp.add(str);
			break;
		}
		case 3: {
			string str1;
			cout << "请输入您的姓名:" << endl;
			cin >> str1;
			cpp.cut(str1);
			system("pause");
			break;
		}
		case 4: {
			while (1) {
				system("cls");
				string str2;
				cout << "请输入您想录入成绩的学生姓名:" << endl;
				cin >> str2;
				string name = str2;
				if (cpp.judge(str2)) {
					Student str2;
					int num;
					cout << "请输入您该名学生的学号：";
					cin >> num;
					int data;
					cout << "请输入该名学生的成绩：";
					cin >> data;
					str2.modify(name,num, data);
					cpp.add(str2);
				}
				else {
					cout << "无此人";
				}
				cout << "是否要录入下一位学生的成绩：1.是   2.否 " << endl;
				int choose;
				cin >> choose;
				if (choose == 1) {
					continue;
				}
				else {
					break;
				}
			}
			break;
		case 5: {
			string str3;
			cout << "请输入您想查看的学生的姓名：";
			cin >> str3;
			if (cpp.judge(str3)) {
				cpp.display(str3);
				system("pause");
			}
		}
		case 6:
			goto END;
		}
		}
	}
	END:;
}
