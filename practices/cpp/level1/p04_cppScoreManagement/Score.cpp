#include "Score.h"
#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;
using std::cin;
Score::Score(string subject){
	Subject=subject;
	for(int i=0;i<30;i++){
		student[i].name="";
		student[i].number="";
		student[i].score=0;	
	}
}
void Score::disp(){
	system("cls");
	cout<<"Subject:"<<Subject<<endl;
	for(int i=0;i<30;i++){
		if(""==student[i].name)continue;
		cout<<"Name:"<<student[i].name<<endl;
		cout<<"Number:"<<student[i].number<<endl;
		cout<<"Score:"<<student[i].score<<endl;
	}
}
void Score::add(){
	int index=-1;
	for(int i=0;i<30;i++){
		if(""==student[i].name){
			index=i;
			break;
		}
	}
	if(-1==index){
		cout<<"Full!\n";
		system("pause");
	}
	else{
		cout<<"Please enter student's name:\n";
		getline(cin,student[index].name);
		cout<<"Please enter student's number:\n";
		getline(cin,student[index].number);
	}
}
void Score::del(){
	string input;
	cout<<"Please enter the name you want to delete:\n";
	cin>>input;
	for(int i=0;i<30;i++){
		if(student[i].name==input){
			student[i].name="";
			student[i].number="";
			student[i].score=0;
			break;
		}
	}
}
void Score::write(){
	
	for(int i=0;i<30;i++){
		if(student[i].name!=""){
			cout<<"Enter the score of "<<student[i].name<<":\n";
			cin>>student[i].score;
		}
	}
}
