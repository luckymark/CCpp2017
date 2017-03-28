#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct MENU{
	char name[9];
	int number;
}menu[1000];

int menuLength=0;

void list();
void input();
void output();

int main(){
	int instruction=0;
	FILE *fp=NULL;
	fp=fopen("p12_wareHouseMenu.txt","r");
	for (menuLength=0;fscanf(fp,"%s%d",menu[menuLength+1].name,&menu[menuLength+1].number)!=EOF;menuLength++);
	fclose(fp);
	fp=NULL;
	
	while (1){
		printf("����1����ʾ����б�\n");
		printf("����2����⣻\n");
		printf("����3�Գ��⣻\n");
		printf("����4�Խ�������\n");
		printf("����Ҫ��ʲô��");
		scanf("%d",&instruction);
		switch (instruction){
			case 1:	list();break;
			case 2:	input();break;
			case 3:	output();break;
			case 4:	break;
		}
		system("cls");
	}
	
	fp=fopen("p12_wareHouseMenu.txt","w");
	for (int i=1;i<=menuLength;i++){
		fprintf(fp,"%8s    %8d\n",menu[i].name,menu[i].number);
	}
	fclose(fp);
	fp=NULL;
	return 0;
}

void list(){
	if (menuLength==0){
		printf("�ֿ�����û�ж����ˣ������������ˣ���ȥ������\n");
	}
	else{
		printf("     ��Ʒ�ͺ�    �������\n");
		for (int i=1;i<=menuLength;i++){
			printf("%3d: %8s    %8d\n",i,menu[i].name,menu[i].number);
		}
	}
	printf("���������������\n");
	getch();
}

void input(){
	while (1){
		char newName[9],instruction=0;
		int newNumber;
		printf("�������ͺţ�8���ַ����ڣ���������");
		scanf("%s%d",newName,&newNumber);
		
		for (int i=1;i<=menuLength;i++){
			if (strcmp(newName,menu[i].name)==0){
				menu[i].number+=newNumber;
				break;
			}
			else if (i==menuLength){
				menuLength++;
				strcpy(menu[menuLength].name,newName);
				menu[menuLength].number=newNumber;
				break;
			}
		}
		
		printf("\n���������Y/N��");
		while(instruction!='N'){
			instruction=getchar();
		}
		if (instruction=='N'){
			break;
		}
	}
}

void output(){
	if (menuLength==0){
		printf("�ֿ�����û�ж����ˣ������������ˣ���ȥ������\n");
		printf("���������������\n");
		getch();
		return;
	}
	
	while (1){
		char newName[9],instruction=0;
		int newNumber;
		printf("�������ͺţ�8���ַ����ڣ���������");
		scanf("%s%d",newName,&newNumber);
		
		for (int i=1;i<=menuLength;i++){
			if (strcmp(newName,menu[i].name)==0){
				if (newNumber<=menu[i].number){
					menu[i].number-=newNumber;
				}
				else{
					while (1){
						printf("��Ʒ%s��ʣ%d����������������������0��������:");
						scanf("%d",&newNumber);
						if (newNumber==0){
							break;
						}
						else if (newNumber<=menu[i].number){
							menu[i].number-=newNumber;
							break;
						}
					}
				}
				break;
			}
			else if (i==menuLength){
				printf("�ͺŴ���\n");
				break;
			}
		}
		
		printf("\n����������Y/N��");
		while(instruction!='N'){
			instruction=getchar();
		}
		if (instruction=='N'){
			break;
		}
	}
}
