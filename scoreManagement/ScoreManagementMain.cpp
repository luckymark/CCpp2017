#include "System.h"
using namespace std;

int main(){
	
	System management;
	string StudentName,CourseName,StudentNum;
	char StudentName_c[100],CourseName_c[100],StudentNum_c[100];
	int Score;
	int op;
	
	FILE* fp=fopen("SCORE_MANAGEMENT.txt","r");
	int CourseSum;
	while(fscanf(fp,"%s%s%d",StudentName_c,StudentNum_c,&CourseSum)!=EOF){
		management.AddStudent(StudentName=StudentName_c,StudentNum=StudentNum_c);
		for(int i=0;i<CourseSum;++i){
			fscanf(fp,"%s%d",CourseName_c,&Score);
			management.AddScore_of(StudentNum,CourseName=CourseName_c,Score);
		}
	}
	fclose(fp);
	
	while(1){
		scanf("%d",&op);
		if(op==1){
			management.ShowStudents();
		}
		else if(op==2){
			puts("请输入学生姓名及学号！");
			cin>>StudentName>>StudentNum;
			management.AddStudent(StudentName,StudentNum);
		}
		else if(op==3){
			puts("请输入学生学号！");
			cin>>StudentNum;
			management.DeleteStudent(StudentNum);
		}
		else if(op==4){
			puts("请输入学生学号 课程名称 及该课程得分！");
			cin>>StudentNum>>CourseName>>Score;
			management.AddScore_of(StudentNum,CourseName,Score);
			char opt[3];
			while(1){
				puts("是否继续为该学生添加课程及得分？Y:是，N:否");
				scanf("%s",opt);
				if(opt[0]=='Y'){
					cout<<"请输入学生"<<StudentNum<<"的课程名称 及该课程得分！"<<endl;
					cin>>CourseName>>Score;
					management.AddScore_of(StudentNum,CourseName,Score);
				}
				else{
					break;
				}
			}
		}
		else if(op==5){
			puts("请输入学生学号 及课程名称！");
			cin>>StudentNum>>CourseName;
			management.DeleteCourse_of(StudentNum,CourseName);
			char opt[3];
			while(1){
				puts("是否继续为该学生删除课程？Y:是，N:否");
				scanf("%s",opt);
				if(opt[0]=='Y'){
					cout<<"请输入学生"<<StudentNum<<"的课程名称！"<<endl;
					cin>>CourseName;
					management.DeleteCourse_of(StudentNum,CourseName);
				}
				else{
					break;
				}
			}
		}
		else{
			break;
		}
	}
	return 0;
}
