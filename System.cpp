#include "System.h"

System::System(){
	students.clear();
	puts("//////////////////////");
	puts("这是一个学生考试成绩管理系统，请输入以下的数字并按下回车来获取相应的功能！");
	puts("1.查看学生名单（含所有成绩信息）");
	puts("2.添加学生");
	puts("3.删除学生（一般在学生的所有成绩信息均为空时调用）");
	puts("4.为某位学生添加课程及分数");
	puts("5.为某位学生删除某课程");
	puts("6.退出系统");
	puts("//////////////////////");
}

System::~System(){
	FILE* fp=fopen("SCORE_MANAGEMENT.txt","w");
	for(vector<Student>::iterator it=students.begin();it!=students.end();++it){
		fprintf(fp,"%s %s\n",it->GetStudentName().c_str(),it->GetStudentNum().c_str());
		fprintf(fp,"%d\n",it->courses.size());
		for(vector<Course>::iterator jt=it->courses.begin();jt!=it->courses.end();++jt){
			fprintf(fp,"%s %d\n",jt->GetCourseName().c_str(),jt->GetScore());
		}
		puts("");
	}
	fclose(fp);
};

bool System::AddStudent(string StudentName,string StudentNum){
	for(vector<Student>::iterator it=students.begin();it!=students.end();++it){
		if(it->GetStudentNum()==StudentNum){
			puts("学生已存在！");
			return 0;
		}
	}
	students.push_back(Student(StudentName,StudentNum));
	return 1;
}

bool System::AddScore_of(string StudentNum,string CourseName,int Score){
	for(vector<Student>::iterator it=students.begin();it!=students.end();++it){
		if(it->GetStudentNum()==StudentNum){
			return it->AddCourse(CourseName,Score);
		}
	}
	puts("学生不存在！");
	return 0;
}

bool System::DeleteCourse_of(string StudentNum,string CourseName){
	for(vector<Student>::iterator it=students.begin();it!=students.end();++it){
		if(it->GetStudentNum()==StudentNum){
			return it->DeleteCourse(CourseName);
		}
	}
	puts("学生不存在！");
	return 0;
}

bool System::DeleteStudent(string StudentNum){
	for(vector<Student>::iterator it=students.begin();it!=students.end();++it){
		if(it->GetStudentNum()==StudentNum){
			students.erase(it);
			return 1;
		}
	}
	puts("学生不存在！");
	return 0;
}

void System::ShowStudents(){
	if(students.empty()){
		puts("The System is Empty!");
		return;
	}
	for(vector<Student>::iterator it=students.begin();it!=students.end();++it){
		cout<<it->GetStudentName()<<' '<<it->GetStudentNum()<<endl;
		for(vector<Course>::iterator jt=it->courses.begin();jt!=it->courses.end();++jt){
			cout<<jt->GetCourseName()<<' '<<jt->GetScore()<<endl;
		}
		puts("");
	}
}
