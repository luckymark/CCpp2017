#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <string>
#include <cstdlib>
#include <conio.h>
using namespace std;
class Student
{
private:
	int number,score;
	string name;
public:
	Student(int number,string name):number(number),name(name)
	{
		score=-1;
	}
	Student(int number,int score,string name):number(number),score(score),name(name){}
	Student(){}
	
	int getNumber() const 
	{
		return this->number;
	}
	
	int getScore() const
	{
		return this->score;
	}
	void setScore(int x) 
	{
		this->score=x;
	}
	string getName() const
	{
		return this->name;
	} 
};
list<Student> students;

int n;

void Pre();
void ShowMenu();
void ShowList();
void Add();
void Remove();
void LogScore();

int main()
{
	Pre();
	while(true)
	{
		ShowMenu();
		cin>>n;
		switch(n)
		{
			case 1:ShowList();break;
			case 2:Add();break;
			case 3:Remove();break;
			case 4:LogScore();break;
			case 5:return 0;break;
		}
		cout<<"enter any key to continue";
		while(!kbhit());
		system("cls");		
	}
	return 0;
}
void Pre()
{
	students.push_back(Student(1,"zhang 3"));
	students.push_back(Student(2,"li 4"));
	students.push_back(Student(3,"wang 5"));
}
void ShowMenu()
{
	printf("\n\n\n");
	printf("\tplease enter a number to select a function:\n");
	printf("\t1.watch student list\n");
	printf("\t2.add student\n");
	printf("\t3.remove student\n");
	printf("\t4.log score\n");
	printf("\t5.exit program\n");
}

void ShowList()
{
	list<Student>::iterator it;
	for(it=students.begin();it!=students.end();it++)
	{
		cout<<(*it).getNumber()<<" "<<(*it).getName()<<" :";
		if((*it).getScore()==-1)
		{
			cout<<"no score"<<endl;
		}else
		{
			cout<<(*it).getScore()<<endl;
		}
	}
}
void Add()
{
	int number;
	string name;
	cout<<"enter number and name"<<endl;
	cin>>number>>name;
	students.push_back(Student(number,name));
}
void Remove()
{
	int number;
	cout<<"enter number of the student you want to remove"<<endl;
	cin>>number;
	for(list<Student>::iterator it=students.begin();it!=students.end();)
	{
		if((*it).getNumber()==number)
		{
			it=students.erase(it);
		}else
		{
			it++;
		}
	}
}
void LogScore()
{
	int number,score;
	while(1)
	{
		cout<<"enter a number you want to log a score"<<endl;
		cin>>number;
		cout<<"enter the student's score"<<endl;
		cin>>score;
		for(list<Student>::iterator it=students.begin();it!=students.end();it++)
		{
			if((*it).getNumber()==number)
			{
				(*it).setScore(score);
				break;
			}
		}
		string judge;
		cout<<"if you want to continue(Y or N)"<<endl;
		cin>>judge;
		if(judge==("Y"));
		else break;
	}
}
