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
		printf("�����������ִ������\n"); 
		printf("1����ӿγ�\n"); 
		printf("2������γ̹���\n");
		scanf("%d",&order);
		if (order==1){
			printf("������γ�������Ӣ���");
			scanf("%s",&name); 
			for (int i=0;i<classNum;i++){
				if (strcmp(name,className[i])==0){
					printf("�γ��Ѵ���\n");
					goto loop; 
				}
			}
			strcpy(className[classNum],name);
			classNum++;
		}
		else if (order==2){
			printf("������γ�������Ӣ���");
			scanf("%s",&name); 
			for (int i=0;i<classNum;i++){
				if (strcmp(name,className[i])==0){
					list(i);
					goto loop;
				}
			}
			printf("�γ̲�����\n");
		}
	}
	return 0;
}

void list(int classNumber){
	int order=0;
	while(1){
		printf("�����������ִ������\n");
		printf("1���鿴ѧ������\n");
		printf("2��ѡ�Σ����ѧ����\n");
		printf("3���˿Σ�ɾ��ѧ����\n");
		printf("4��¼��ɼ�\n");
		printf("5���˳�����\n");
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
