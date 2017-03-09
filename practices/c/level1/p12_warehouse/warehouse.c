
#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <malloc.h> 
/*
实现如下的菜单（按数字选择菜单功能）：
	1 显示存货列表
	2 入库
	3 出库
    4 退出程序
实现菜单对应功能（需记录货物的型号、数量等信息）；
程序启动时从文件中读取当前库存数据，退出时保存库存数据；*/



typedef struct tempname//结构 part构造 
{
	int num;
	char* str;
	struct tempname *next;
}part;



void creatlb(part** nd)//初始化链表头 
{
	*nd = NULL;
}

void disp(part** head)
{
	part* cp = *head;
	while (cp != NULL)
	{
		printf("名字为%s，", cp->str);
		printf("存货量为%d\n", cp->num);
		cp = cp->next;
	}
	_getch();
}

int findname(part** head, char* zfc)
{
	part* xp = *head;
	int i = 1;
	int k = 0;
	while (xp != NULL)
	{
		if (strcmp((xp->str),zfc)==0)//只要有相同名字的返回该项在链表中位置，否则返回-1
		{
			return i;
		}
		xp = xp->next;
		i++;
	}
	return 0;
}


void weicha(part** head, part* new_part, int value, char* str)//尾插,将一个新的插入链表
{
	part* cp = *head;//遍历指针
	new_part->num = value;
	new_part->str = str;
	if (*head == NULL)//如果为空 
	{
		*head = new_part;//将头指针指向new part部分
		new_part->next = NULL;//将newpart作为后部分 
	}
	else
	{
		while (cp->next != NULL)
		{
			cp = cp->next;
		}
		cp->next = new_part;
		new_part->next = NULL;
	}
}

int main(void)
{

	part* head;
	creatlb(&head);
	
	


//以下为读取文件


	FILE *fp = fopen("userinfo.txt", "r");
	if (fp == NULL)
	{
		printf("can not open or create file!");
		system("pause");
		return 0;
	}
	else
	{
		while(!feof(fp))
		{
			char* sp=(char*)malloc(20*sizeof(char));
			int x;
			if(fscanf(fp,"%s %d ",sp,&x)==2)
			{
				part* new_part = (part*)malloc(sizeof(part));
				weicha(&head, new_part, x, sp);//将store读取的值插入链表后
			}
			
		}
	}
	fclose(fp);






//以下为开始界面
	while (1) 
	{

		system("cls");

		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
		printf("\n\n\n\n\n\n\n\n\n\t                         A simple warehouse\n");//hello
		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		printf("\n\t                      Please choose an option!\n");
		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_BLUE);
		printf("\n\t                       1:Show inventory list\n");
		printf("\t                              2:import\n");
		printf("\t                              3:export\n");
		printf("\t                           4:save and exit");
		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);




//以下为用户交互


	
		char cos = _getch();
		int slsl;
		if (cos == '1')//显示存货列表
		{
			system("cls");
			disp(&head);

		}
		else if (cos == '2')//入库
		{
			char* ap=(char*)malloc(60*sizeof(char));
			system("cls");
			printf("请输入要入库商品的名字:");
			scanf("%s", ap);
			printf("请输入要入库商品的数量:");
			scanf("%d", &slsl);
			if (findname(&head, ap) != 0)//若有重名商品存在
			{

				_getch();
				part* cp = head;
				for(int i=1;i<findname(&head, ap);i++)
				{
					cp = cp->next;
				}
				cp->num = cp->num+slsl;
			}
			else
			{
				part* new_part = (part*)malloc(sizeof(part));
				weicha(&head, new_part, slsl, ap);
			}
			printf("商品已入库！");
			_getch();



		}
		else if (cos == '3')//出库
		{
			char* ap=(char*)malloc(20*sizeof(char));
			system("cls");
			printf("请输入要出库商品的名字:");
			scanf("%s", ap);
			
			if (findname(&head, ap) != 0)//若有重名商品存在
			{
				printf("请输入要出库商品的数量:");
				scanf("%d", &slsl);
				part* cp = head;
				for (int i = 1; i<findname(&head, ap); i++)
				{
					cp = cp->next;
				}
				if (cp->num >= slsl)
				{
					cp->num = cp->num - slsl;
					printf("商品出库成功！");
					_getch();
				}
				else
				{
					printf("商品数量不足！目前库中只有%d个商品！", cp->num);
					_getch();
				}
			}
			else
			{
				printf("商品不存在！");
				_getch();
			}


		}
		else if (cos == '4')//退出程序
		{
			
			
			FILE *op = fopen("userinfo.txt", "w");
			if (op == NULL)
			{
				printf("此次入库存储失败！");
				system("pause");
				return 0;
			}
			else
			{
				int y;
				part* cp = head;
				while (cp != NULL)
				{
					char* wp=(char*)malloc(20*sizeof(char));
					y=cp->num;
					wp=cp->str;
					fprintf(fp,"%s %d ",wp,y);
					{
						cp = cp->next;
					}
				}
			}
			fclose(fp);
			
			
			return 0;
			
			
		}
	}
	return 0;
	}
	






