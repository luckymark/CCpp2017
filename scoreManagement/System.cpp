#include "System.h"

System::System(){
	students.clear();
	puts("//////////////////////");
	puts("����һ��ѧ�����Գɼ�����ϵͳ�����������µ����ֲ����»س�����ȡ��Ӧ�Ĺ��ܣ�");
	puts("1.�鿴ѧ�������������гɼ���Ϣ��");
	puts("2.���ѧ��");
	puts("3.ɾ��ѧ����һ����ѧ�������гɼ���Ϣ��Ϊ��ʱ���ã�");
	puts("4.Ϊĳλѧ����ӿγ̼�����");
	puts("5.Ϊĳλѧ��ɾ��ĳ�γ�");
	puts("6.�˳�ϵͳ");
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
		fprintf(fp,"\n");
	}
	fclose(fp);
};

bool System::AddStudent(string StudentName,string StudentNum){
	for(vector<Student>::iterator it=students.begin();it!=students.end();++it){
		if(it->GetStudentNum()==StudentNum){
			puts("ѧ���Ѵ��ڣ�");
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
	puts("ѧ�������ڣ�");
	return 0;
}

bool System::DeleteCourse_of(string StudentNum,string CourseName){
	for(vector<Student>::iterator it=students.begin();it!=students.end();++it){
		if(it->GetStudentNum()==StudentNum){
			return it->DeleteCourse(CourseName);
		}
	}
	puts("ѧ�������ڣ�");
	return 0;
}

bool System::DeleteStudent(string StudentNum){
	for(vector<Student>::iterator it=students.begin();it!=students.end();++it){
		if(it->GetStudentNum()==StudentNum){
			students.erase(it);
			return 1;
		}
	}
	puts("ѧ�������ڣ�");
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
