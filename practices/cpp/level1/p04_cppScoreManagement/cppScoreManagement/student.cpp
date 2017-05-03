#include <iostream>
#include <string>
using namespace std;

#include "student.h"
student::student()
{
	count=0;
	for(int i=0;i<100;i++)
	{
		student0[i].name="0";
		cin>>student0[i].name;
		cin>>student0[i].ID;
		cin>>student0[i].score;
	}
	for(int i=0;i<100;i++)
	{
		if(student0[i].name!="0") 
		{
			count++;
			cout<<"name:"<<student0[i].name<<' ';
		    cout<<"ID:"<<student0[i].ID<<' ';
		    cout<<"score:"<<student0[i].score<<' '<<endl;
		}
	}
}
void student::menu()
{
	cout<<"1:add "<<endl<<"2:find"<<endl;
	cout<<"3:remove "<<endl<<"4:exit"<<endl;
	cout<<"input your choice";
	cin>>choice; 
	switch (choice)
	{
		case 1:add();
		menu();
		break;
		case 2:find();
		menu();
		break;
		case 3:remove();
		menu();
		break;
		case 4:exit();
		break;
	}
}
void student::add()
{
	int n=1;
	while(n!=0)
	{
		cout<<"please input name£º"<<endl;
		cin>>student0[count].name;
		cout<<"please input ID£º"<<endl;
		cin>>student0[count].ID;	
		cout<<"please input score£º"<<endl;
		cin>>student0[count].score; 
		count++;
		cout<<"1£º¼ÌÐø 0£ºÍ£Ö¹"<<endl;
		cin>>n;
	}
}
void student::remove()
{
	cout<<"please input name"<<endl;
	string name1;
	cin>>name1;
	for(int i=0;i<=count;i++)
	{
		if(name1==student0[i].name)
		{
			cout<<name1<<' '<<"delete succeed!"<<endl;
			existence=1;
			student0[i].name="0";
			student0[i].ID="0";
			student0[i].score=0;
			break;
		}
		if(i==count)
		{
			existence==0;
		}
	}
	if(existence==0)
	{
		cout<<"no people called:"<<name1<<endl;
	}
	if(existence==1)
	{
		count--;
	}
}
void student::find()
{
	string name0;
	cout<<"please input name"<<endl; 
	cin>>name0;
	for(int i=0;i<=count;i++)
	{
		if(name0==student0[i].name)
		{
			cout<<"name:"<<student0[i].name<<' ';
			cout<<"ID:"<<student0[i].ID<<' ';
			cout<<"score:"<<student0[i].score<<endl;
			goto end;
		}
	}
	cout<<"no people called:"<<name0<<endl;
	end:;
}
int student::exit()
{
	return 0;
}

