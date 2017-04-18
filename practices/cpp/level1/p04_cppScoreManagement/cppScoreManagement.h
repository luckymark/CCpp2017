#include<iostream>
#include<string>
using namespace std;
class Student
{
public:
	void display();
	void modify(string name,int num, int cppmark);
	string name = "n";
	int cppmark = 0;
	int num = 0;
};

class Class
{
public:
	void add(string name);
	void add(Student);
	void cut(string name);
	void display2();
	void display(string name);
	bool judge(string name);
	Class()
	{
		for (int i = 0;i < 30;i++) {
			list[i] = "n";
		}
	}

private:
	string list[30];
	static int No;
	Student str[30];
};
