#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <list>
#include <string>


using namespace std;

class Student
{
  private:
    int number, score;
    string name;

  public:
    Student(int number, string name) : number(number), name(name)
    {
		score = -1;
    }

    int getNumber()
    {
		return this->number;
    }

    int getScore()
    {
		return this->score;
    }
    void setScore(int n)
    {
		this->score = n;
    }
    string getName()
    {
		return this->name;
    }
};
list<Student> students;

void Init();
void ShowMenu();
void ShowList();
void Add();
void Delete();
void InputScore();

int main()
{
    int n;
    Init();
    while (1)
    {
	ShowMenu();
	cin >> n;
	switch (n)
	{
	case 1:
	    ShowList();
	    break;
	case 2:
	    Add();
	    break;
	case 3:
	    Delete();
	    break;
	case 4:
	    InputScore();
	    break;
	case 5:
	    return 0;
	    break;
	}

    }
    return 0;
}
void Init()
{
    students.push_back(Student(1, "王大锤"));
    students.push_back(Student(2, "小李子"));
}
void ShowMenu()
{
    cout<<"\nwhat do you want to do?"<<endl;
    cout<<"1.show student information."<<endl;
    cout<<"2.add student."<<endl;
    cout<<"3.delete student."<<endl;
    cout<<"4.record score."<<endl;
    cout<<"5.exit program."<<endl;
}

void ShowList()
{
    cout<<"student number      name      score"<<endl;
    list<Student>::iterator it;
    for (it = students.begin(); it != students.end(); it++)
    {
	cout <<"   "<< (*it).getNumber() << "              " << (*it).getName() <<"      ";
	if ((*it).getScore() == -1)
	{
	    cout << "no score" << endl;
	}
	else
	{
	    cout << (*it).getScore() << endl;
	}
    }
}
void Add()
{
    int number;
    string name;
    cout << "enter number and name" << endl;
    cin >> number >> name;
    students.push_back(Student(number, name));
}
void Delete()
{
    int number;
    cout << "enter number of the student you want to remove" << endl;
    cin >> number;
    for (list<Student>::iterator it = students.begin(); it != students.end();)
    {
	if ((*it).getNumber() == number)
	{
	    it = students.erase(it);
	}
	else
	{
	    it++;
	}
    }
}
void InputScore()
{
    int number, score;
    while (1)
    {
	cout << "enter a number you want to log a score" << endl;
	cin >> number;
	cout << "enter the student's score" << endl;
	cin >> score;
	for (list<Student>::iterator it = students.begin(); it != students.end(); it++)
	{
	    if ((*it).getNumber() == number)
	    {
		(*it).setScore(score);
		break;
	    }
	}
	string judge;
	cout << "if you want to continue(Y or N)" << endl;
	cin >> judge;
	if (judge == ("Y"))
	    ;
	else
	    break;
    }
}
