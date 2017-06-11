#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "CLASS.h"

void Classes::showList()
{
	for (int i=1;i<=totalNumber;i++)
	{
		if (student[i].name[0]!=0)
		{
			printf("%s   %s   %d\n",student[i].studentNumber,student[i].name,student[i].grade);		
		}
	}
}
		

void Classes::deleteStudent()
{
	MAXN=150;
	char tmpName[20],tmpNumber[20];
	int order=0;
	while(1)
	{
		if (totalNumber==0)
		{
			printf("Faliure!\n");
			return;
		}
		loop:
		printf("Input name & student number:");
		scanf("%s %s",tmpName,tmpNumber);
		for (int i=1;i<=totalNumber;i++)
		{
			if (strcmp(tmpName,student[i].studentNumber)==0)
			{
				totalNumber--;
				student[i].name[0]=0;
				goto loop; 
			}
		}
		printf("Not Exist!\n");
		printf("Continue£¿1=YES/0=NO\n");
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
			printf("No info!\n");
			return;
		}
		loop:
		printf("Input Name & Number:");
		scanf("%s %s",tmpName,tmpNumber);
		for (int i=1;i<=totalNumber;i++){
			if (strcmp(tmpName,student[i].studentNumber)==0){
				printf("Input grade£º");
				scanf("%d",&tmpGrade);
				student[i].grade=tmpGrade;
				goto loop; 
			}
		}
		printf("Not exist!\n");
		printf("Continue£¿1=YES/0=NO\n");
		scanf("%d",&order);
		if (order==0)	break;
	}
}
void Classes::addStudent(){
	char tmpName[20],tmpNumber[20];
	int order=0;
	while(1)
	{
		if (totalNumber>=MAXN)
		{
			printf("Full!\n");
			return;
		}
		loop:
		printf("Input name&student number");
		scanf("%s %s",tmpName,tmpNumber);
		for (int i=1;i<=totalNumber;i++){
			if (strcmp(tmpName,student[i].studentNumber)==0){
				printf("Exists!\n");
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
		printf("Continue£¿1=YES  0=NO\n");
		scanf("%d",&order);
		if (order==0)	break;
	}
}

