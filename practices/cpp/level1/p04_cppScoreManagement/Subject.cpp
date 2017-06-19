#include "Subject.h"
#include<iostream>
using namespace std;

void Subject::student_in(string Name, string Id, double Score){
	student.push_back(Student(Name, Id, Score));
}

void Subject::show(){
	cout<<"姓名  学号  成绩"<<endl<<endl;
	for(i=student.begin(); i!=student.end(); i++){
		cout<<(*i).name<<' '<<(*i).id<<' '<<(*i).score<<endl;
	}
	cout<<endl;
	system("pause"); 
}

void Subject::student_out(string Id){
	for(i=student.begin(); i!=student.end(); i++){
		if((*i).id==Id){
			student.erase(i);
			cout<<"Remove successful!"<<endl;
			break;
		}
	}
}

void Subject::score_in(string Id){
	bool flag = 0;
	double Score;
	for(i=student.begin(); i!=student.end(); i++){
		if(!flag){
			if((*i).id==Id){
				cout<<"请输入学号为"<<(*i).id<<" 的学生的成绩：";
				cin >> Score;
				(*i).score = Score;
				flag = 1;
			}
		}
		else{
			cout<<"请输入学号为"<<(*i).id<<" 的学生的成绩：";
			cin>>Score;
			(*i).score = Score;
		}
	}
}
