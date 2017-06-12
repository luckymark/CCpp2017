# include"cppScoreManagement.h"
#include <iomanip>

void Student::display()
{
	using namespace std;
	cout << setw(10) << name << setw(10) << num << setw(10) <<cppmark<<endl;
}

void Student::modify(string name,int num, int cppmark)
{
	this->name = name;
	this->num = num;
	this->cppmark = cppmark;
}

void Class::add(string name)
{
	using namespace std;
	for (int i = 0;i < 30;i++) {
		if (list[i] == "n") {
			list[i] = name;
			No += 1;
			break;
		}
		cout << "班级已满" << endl;
	}
}

void Class::add(Student name)
{
	for (int i = 0;i < 30;i++) {
		if (str[i].name == "n") {
			str[i] = name;
			break;
		}
	}
}

void Class::cut(string name)
{
	using namespace std;
	for (int i = 0;i < 30;i++) {
		if (list[i]==name){
			list[i] ="n";
			str[i].name = "n";
			No -= 1;
			break;
		}
		if (i = 29) {
			cout << "班级中无此人" << endl;
		}
	}
}

void Class::display2()
{
	using namespace std;
	cout << "共有" << No << "位学生选了该门课" << endl;
	for (int i = 0;i < 30;i++) {
		if (list[i] != "n") {
			cout <<i+1<<"."<< list[i] << endl;
		}
	}
}

void Class::display(string name)
{
	using namespace std;
	for (int i = 0;i < 30;i++) {
		if (str[i].name ==name) {
			str[i].display();
		}
	}
}

bool Class::judge(string name)
{
	for (int i = 0;i < 30;i++) {
		if (list[i] == name) {
			return true;
		}
	}
	return false;
}

int Class::No = 0;

