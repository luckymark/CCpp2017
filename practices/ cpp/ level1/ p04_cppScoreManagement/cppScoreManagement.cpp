#include <iostream>
#include<windows.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int sleep_time = 2000;
class student {
private:
	struct DATA {
		int stu_no;		//学生编号
		char name[20];		//姓名
		int score;		//成绩
		struct DATA *next;
	};
	struct DATA *head, *p_new, *temp1, *temp2;
public:
	student();
	void show();
	void add_stu();
	void del_stu();
	void get_score();
};

student::student()
{
	head = NULL;
}
void student::add_stu()		//添加学生信息的函数
{
	int if_add;
	while (1) {
		int have_exist = 0;		//用于判定将要加入的学生是否已存在
		p_new = new(struct DATA);
		cout << "请输入学生的学号：" << endl;
		cin >> p_new->stu_no;
		temp1 = head;
		while (temp1 != NULL) {
			if (temp1->stu_no == p_new->stu_no) {
				cout << "该学生信息已存在，若要继续添加，请先删除" << endl;
				Sleep(sleep_time);
				have_exist = 1;
				break;
			}
			temp1 = 
				temp1->next;
		}
		if (have_exist) {
			break;
		}
		cout << "请输入学生的姓名：" << endl;
		cin >> p_new->name;
		p_new->score = 0;
		p_new->next = head;
		head = p_new;
		cout << "选择即将进行操作的序号" << endl;
		cout << "1.继续添加" << endl;
		cout << "2.返回上一层" << endl;
		cin >> if_add;
		if (2==if_add) {
			break;
		}
	}
}
void student::del_stu()		//删除学生信息的函数
{
	int number;			//存储将要删除对象的编号
	while (1) {
		int have_find = 0;
		cout << "请输入删除对象的编号" << endl;
		cin >> number;
		temp1 = head;
		temp2 = 
			head->next;
		if (temp2==NULL) {
			if (temp1->stu_no == number) {
				head = temp2;
				delete(temp1);
				cout << "删除成功" << endl;
				Sleep(sleep_time);
				break;
			}
			else {
				cout << "信息库中无该对象" << endl;
				Sleep(sleep_time);
				break;
			}
		}
		else if(1){
			if (temp1->stu_no == number) {
				head = temp2;
				delete(temp1);
				cout << "删除成功" << endl;
				Sleep(sleep_time);
				break;
			}
			else {
				while (temp2 != NULL) {
					if (temp2->stu_no == number) {
						have_find++;
						temp1->next =
							temp2->next;
						delete(temp2);
						cout << "删除成功" << endl;
						Sleep(sleep_time);
						break;
					}
					if (have_find == 0) {
						temp1 = temp2;
						temp2 = 
							temp2->next;
					}
				}
			}
			if (have_find) {
				break;
			}
			else {
				cout << "信息库中无该对象" << endl;
				Sleep(sleep_time);
				break;
			}
		}
	}
}
void student::get_score()		//添加学生成绩的函数
{
	int if_get;
	while (1) {
		cout << "请输入进行添加成绩对象的号码：" << endl;
		int number;
		cin >> number;
		int if_find = 0;
		temp1 = head;
		while (temp1 != NULL) {
			if (temp1->stu_no == number) {
				cout << "请输入分数" << endl;
				cin >> temp1->score;
				if_find++;
				break;
			}
			temp1 =
				temp1->next;
		}
		if (0 == if_find) {
			cout << "没有该学生的信息！" << endl;
			cout << "选择即将进行操作的序号" << endl;
			cout << "1.继续添加" << endl;
			cout << "2.返回上一层" << endl;
			cin >> if_get;
			if (2 == if_get) {
				break;
			}
		}if (0 != if_find) {
			cout << "选择即将进行操作的序号" << endl;
			cout << "1.继续添加" << endl;
			cout << "2.返回上一层" << endl;
			cin >> if_get;
			if (2 == if_get) {
				break;
			}
		}
	}
}
void student::show()		//显示学生信息的函数
{
	cout << "学生编号" << "\t\t" << "学生姓名" << "\t\t" << "学生成绩" << endl;
	temp1 = head;
	while (temp1 != NULL)
	{
		cout << temp1->stu_no << "\t\t\t" << temp1->name << "\t\t\t" << temp1->score << endl;
		temp1 = temp1->next;
	}
}

int main(int argc, char** argv) {
	class student STUDENT;
	while (1) {
		system("cls");
		cout << "请输入将要执行操作的编号：" << endl;
		cout << "1.查看学生名单;" << endl;
		cout << "2.添加学生;" << endl;
		cout << "3.删除学生;" << endl;
		cout << "4.录入成绩;" << endl;
		cout << "5.退出程序;" << endl;
		int n;
		cin >> n;
		system("cls");
		switch (n) {
		case 1:
			STUDENT.show();
			int if_show;
			cout << "选择即将进行操作的序号" << endl;
			cout << "1.返回上一层" << endl;
			cout << "2.退出程序" << endl;
			cin >> if_show;
			if (1 == if_show) {
				break;
			}
			else {
				return -1;
			}
		case 2:
			STUDENT.add_stu();
			break;
		case 3:
			STUDENT.del_stu();
			break;
		case 4:
			STUDENT.get_score();
			break;
		case 5:
			return -1;
		default:
			cout << "没有该选项！";
			Sleep(sleep_time);
		}
	}
	return 0;
}
