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
			puts("������ѧ��������ѧ�ţ�");
			cin>>StudentName>>StudentNum;
			management.AddStudent(StudentName,StudentNum);
		}
		else if(op==3){
			puts("������ѧ��ѧ�ţ�");
			cin>>StudentNum;
			management.DeleteStudent(StudentNum);
		}
		else if(op==4){
			puts("������ѧ��ѧ�� �γ����� ���ÿγ̵÷֣�");
			cin>>StudentNum>>CourseName>>Score;
			management.AddScore_of(StudentNum,CourseName,Score);
			char opt[3];
			while(1){
				puts("�Ƿ����Ϊ��ѧ����ӿγ̼��÷֣�Y:�ǣ�N:��");
				scanf("%s",opt);
				if(opt[0]=='Y'){
					cout<<"������ѧ��"<<StudentNum<<"�Ŀγ����� ���ÿγ̵÷֣�"<<endl;
					cin>>CourseName>>Score;
					management.AddScore_of(StudentNum,CourseName,Score);
				}
				else{
					break;
				}
			}
		}
		else if(op==5){
			puts("������ѧ��ѧ�� ���γ����ƣ�");
			cin>>StudentNum>>CourseName;
			management.DeleteCourse_of(StudentNum,CourseName);
			char opt[3];
			while(1){
				puts("�Ƿ����Ϊ��ѧ��ɾ���γ̣�Y:�ǣ�N:��");
				scanf("%s",opt);
				if(opt[0]=='Y'){
					cout<<"������ѧ��"<<StudentNum<<"�Ŀγ����ƣ�"<<endl;
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
