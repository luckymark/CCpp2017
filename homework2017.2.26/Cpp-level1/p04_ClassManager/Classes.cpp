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
			printf("�����������޷���ӣ�����\n");
			return;
		}
		loop:
		printf("���������� ѧ��:");
		scanf("%s %s",tmpName,tmpNumber);
		for (int i=1;i<=totalNumber;i++){
			if (strcmp(tmpName,student[i].studentNumber)==0){
				printf("��ͬѧ�Ѵ���\n");
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
		printf("�Ƿ������1=YES  0=NO\n");
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
			printf("�����ѿգ��޷�ɾ��������\n");
			return;
		}
		loop:
		printf("���������� ѧ��:");
		scanf("%s %s",tmpName,tmpNumber);
		for (int i=1;i<=totalNumber;i++){
			if (strcmp(tmpName,student[i].studentNumber)==0){
				totalNumber--;
				student[i].name[0]=0;
				goto loop; 
			}
		}
		printf("�����ڸ�ͬѧ\n");
		printf("�Ƿ������1=YES/0=NO\n");
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
			printf("û��ѧ�����޷�¼�룬����\n");
			return;
		}
		loop:
		printf("���������� ѧ��:");
		scanf("%s %s",tmpName,tmpNumber);
		for (int i=1;i<=totalNumber;i++){
			if (strcmp(tmpName,student[i].studentNumber)==0){
				printf("������ɼ���");
				scanf("%d",&tmpGrade);
				student[i].grade=tmpGrade;
				goto loop; 
			}
		}
		printf("�����ڸ�ͬѧ\n");
		printf("�Ƿ������1=YES/0=NO\n");
		scanf("%d",&order);
		if (order==0)	break;
	}
}
