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
		printf("输入1以显示存货列表；\n");
		printf("输入2以入库；\n");
		printf("输入3以出库；\n");
		printf("输入4以结束程序；\n");
		printf("你想要做什么：");
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
		printf("仓库里面没有东西了！做不了生意了！快去进货！\n");
	}
	else{
		printf("     物品型号    存货数量\n");
		for (int i=1;i<=menuLength;i++){
			printf("%3d: %8s    %8d\n",i,menu[i].name,menu[i].number);
		}
	}
	printf("按任意键继续……\n");
	getch();
}

void input(){
	while (1){
		char newName[9],instruction=0;
		int newNumber;
		printf("请输入型号（8个字符以内）和数量：");
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
		
		printf("\n继续入库吗？Y/N：");
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
		printf("仓库里面没有东西了！做不了生意了！快去进货！\n");
		printf("按任意键继续……\n");
		getch();
		return;
	}
	
	while (1){
		char newName[9],instruction=0;
		int newNumber;
		printf("请输入型号（8个字符以内）和数量：");
		scanf("%s%d",newName,&newNumber);
		
		for (int i=1;i<=menuLength;i++){
			if (strcmp(newName,menu[i].name)==0){
				if (newNumber<=menu[i].number){
					menu[i].number-=newNumber;
				}
				else{
					while (1){
						printf("物品%s还剩%d，请重新输入数量（输入0以跳过）:");
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
				printf("型号错误！\n");
				break;
			}
		}
		
		printf("\n继续出库吗？Y/N：");
		while(instruction!='N'){
			instruction=getchar();
		}
		if (instruction=='N'){
			break;
		}
	}
}
