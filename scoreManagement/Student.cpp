#include "Student.h"

Student::Student(string name,string num){
	this->name=name;
	this->num=num;
	courses.clear();
}

Student::~Student(){}

string Student::GetStudentName(){
	return name;
}

string Student::GetStudentNum(){
	return num;
}

bool Student::AddCourse(string CourseName,int Score){
	for(vector<Course>::iterator it=courses.begin();it!=courses.end();++it){
		if(it->GetCourseName()==CourseName){
			puts("��ѧ���Ĵ˿γ��Ѵ��ڣ�");
			return 0;
		}
	}
	courses.push_back(Course(CourseName,Score));
	return 1;
}

bool Student::DeleteCourse(string CourseName){
	for(vector<Course>::iterator it=courses.begin();it!=courses.end();++it){
		if(it->GetCourseName()==CourseName){
			courses.erase(it);
			return 1;
		}
	}
	puts("��ѧ���Ĵ˿γ̲����ڣ�");
	return 0;
}
