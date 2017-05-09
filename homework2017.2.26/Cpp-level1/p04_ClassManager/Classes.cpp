#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Classes.h"

void Classes::showList(){
	printf("studentNumber       name                grade\n");
	for (int i=1;i<=totalNumber;i++){
		if (student[i].name[0]!=0){
			printf("%-20s%-20s%-5d\n",student[i].studentNumber,student[i].name,student[i].grade);		
		}
	}
}
		
void Classes::addStudent(){
	MAXN=150;
	char tmpName[20],tmpNumber[20];
	int order=0;
	while(1){
		if (totalNumber>=MAXN){
			printf("人数已满，无法添加，返回\n");
			return;
		}
		loop:
		printf("请输入姓名 学号:");
		scanf("%s %s",tmpName,tmpNumber);
		for (int i=1;i<=totalNumber;i++){
			if (strcmp(tmpName,student[i].studentNumber)==0){
				printf("该同学已存在\n");
				goto loop; 
			}
		}
		totalNumber++;
		for (int i=1;i<=totalNumber;i++){
			if (student[i].name[0]==0){
				strcpy(student[i].name,tmpName);
				strcpy(student[i].studentNumber,tmpNumber);
				break;
			}
		}
		printf("是否继续？1=YES  0=NO\n");
		scanf("%d",&order);
		if (order==0)	break;
	}
}

void Classes::deleteStudent(){
	MAXN=150;
	char tmpName[20],tmpNumber[20];
	int order=0;
	while(1){
		if (totalNumber==0){
			printf("人数已空，无法删除，返回\n");
			return;
		}
		loop:
		printf("请输入姓名 学号:");
		scanf("%s %s",tmpName,tmpNumber);
		for (int i=1;i<=totalNumber;i++){
			if (strcmp(tmpName,student[i].studentNumber)==0){
				totalNumber--;
				student[i].name[0]=0;
				goto loop; 
			}
		}
		printf("不存在该同学\n");
		printf("是否继续？1=YES/0=NO\n");
		scanf("%d",&order);
		if (order==0)	break;
	}
}

void Classes::enteringGrade(){
	MAXN=150;
	int tmpGrade=0,order=0;
	char tmpName[20],tmpNumber[20];
	while(1){
		if (totalNumber==0){
			printf("没有学生，无法录入，返回\n");
			return;
		}
		loop:
		printf("请输入姓名 学号:");
		scanf("%s %s",tmpName,tmpNumber);
		for (int i=1;i<=totalNumber;i++){
			if (strcmp(tmpName,student[i].studentNumber)==0){
				printf("请输入成绩：");
				scanf("%d",&tmpGrade);
				student[i].grade=tmpGrade;
				goto loop; 
			}
		}
		printf("不存在该同学\n");
		printf("是否继续？1=YES/0=NO\n");
		scanf("%d",&order);
		if (order==0)	break;
	}
}
