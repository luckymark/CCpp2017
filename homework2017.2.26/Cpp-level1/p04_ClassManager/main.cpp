#include <cstdio>
#include <cstring>
#include "Classes.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
Classes classes[100];

void list(int classNumber);

int main(int argc, char** argv) {
	char className[100][100],name[100];
	int order=0,classNum=0;
	while (1){
		loop:
		printf("请输入序号以执行任务\n"); 
		printf("1、添加课程\n"); 
		printf("2、进入课程管理\n");
		scanf("%d",&order);
		if (order==1){
			printf("请输入课程名（用英语）：");
			scanf("%s",&name); 
			for (int i=0;i<classNum;i++){
				if (strcmp(name,className[i])==0){
					printf("课程已存在\n");
					goto loop; 
				}
			}
			strcpy(className[classNum],name);
			classNum++;
		}
		else if (order==2){
			printf("请输入课程名（用英语）：");
			scanf("%s",&name); 
			for (int i=0;i<classNum;i++){
				if (strcmp(name,className[i])==0){
					list(i);
					goto loop;
				}
			}
			printf("课程不存在\n");
		}
	}
	return 0;
}

void list(int classNumber){
	int order=0;
	while(1){
		printf("请输入序号以执行任务\n");
		printf("1、查看学生名单\n");
		printf("2、选课（添加学生）\n");
		printf("3、退课（删除学生）\n");
		printf("4、录入成绩\n");
		printf("5、退出程序\n");
		scanf("%d",&order);
		switch(order){
			case 1:	classes[classNumber].showList();break;
			case 2:	classes[classNumber].addStudent();break;
			case 3:	classes[classNumber].deleteStudent();break;
			case 4:	classes[classNumber].enteringGrade();break;
			case 5:	return;
		}
	}
}
