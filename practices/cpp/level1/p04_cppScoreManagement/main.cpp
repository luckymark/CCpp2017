#include <iostream>
#include "Subject.h"
#include <string>
#include <fstream>
using namespace std;
void show_main();
void show_a(int);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
list<Subject> sub;
list<Subject>::iterator i;

int main(int argc, char** argv) {

	sub.push_back(Subject("Math"));	
	sub.push_back(Subject("English"));
	sub.push_back(Subject("Cprogram"));
	
	int user = 0;
	
	while(1){
		system("cls");
		show_main();

	} 
	return 0;
}

void show_main(){
	int index;
	int user;
	while(1)
	{
		index = 1;
		cout<<"================选择课程==============="<<endl;
		for(i=sub.begin(); i!=sub.end(); i++, index++){
			cout<<index<<"."<<(*i).name<<endl;
		}
		cout<<index<<".退出系统"<<endl;
		cin >> user;
		system("cls");
		if(user == index){
			exit(0);
		}
		else{
			show_a(user);
		}
	}
}

void show_a(int user){
	int k;
	string stu_name;
	string stu_id;
	double stu_sco;
	string name;
	int user_a; 
	while(1){
		for(i=sub.begin(), k=0; i!=sub.end(); i++, k++){
			if(k == user-1){
				break;
			}
		}
		cout<<"================"<<(*i).name<<"================"<<endl;
		cout<<"1.查看学生名单"<<endl;
		cout<<"2.选课"<<endl;
		cout<<"3.退选"<<endl;
		cout<<"4.录入成绩"<<endl;
		cout<<"5.返回"<<endl;
		cin >> user_a;
		system("cls");
		if(user_a == 5){
			return;
		}
		else{
			switch(user_a){
				case 1:
					(*i).show();
					break;
				case 2:
					cout<<"请输入学生姓名，学号，成绩"<<endl;
					cin >> stu_name >> stu_id >> stu_sco;
					(*i).student_in(stu_name, stu_id, stu_sco);
					break;
				case 3:
					cout<<"请输入学生学号"<<endl;
					cin >> stu_id;
					(*i).student_out(stu_id);
					break;
				case 4:
					cout<<"请输入开始录入学生的学号"<<endl;
					cin >> stu_id;
					(*i).score_in(stu_id);
					break;
			}
		}
		system("cls");
	}
}
