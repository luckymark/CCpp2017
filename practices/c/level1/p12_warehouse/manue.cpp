/*实现如下的菜单（按数字选择菜单功能）： 2. 显示存货列表 3. 入库 4. 出库 5. 退出程序
实现菜单对应功能（需记录货物的型号、数量等信息）；
程序启动时从文件中读取当前库存数据，退出时保存库存数据；*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include"Windows.h"

struct Item
{
	int name;
	int sum;
};

struct Node
{
	struct Item item;
	struct Node* next;
}* head,* last,* node;

void AddList(struct Item item)
{
	node = (struct Node*)malloc(sizeof(struct Node));
	node->item = item;
	node->next = NULL;
	if(last == NULL)
	{
		head = last = node;
	}else
	{
		last->next = node;
		last = node;
	}
}

struct Item FindList(int x)
{
	struct Node* pos;
	struct Item t;
	for(pos = head;pos != NULL;pos = pos->next)
	{
		if(x == pos->item.name)
		{
			t.name = x;t.sum = pos->item.sum;
			return t;
		}
	}
	t.name = -1;t.sum = -1;
	return t;
}

void Pre()
{
	head = last = node = NULL;
	FILE* f = fopen("tset.txt","r");
	int name;
	int sum;
	while(fscanf(f,"%d%d",&name,&sum) > 0)
	{
		struct Item item;item.name;item.sum = sum;
		AddList(item);
	}
}

void Show1()
{
	struct Node* pos = head;
	for(;pos != NULL;pos = pos->next)
	{
		printf("name is %d /n quantity is %d",pos->item.name,pos->item.sum);
	}
}

void Add(int a,int b)
{
	struct Item item;item.name = a;item.sum = b;
	AddList(item);
}

void Delet(int x)
{
	struct Node* t1 = head,* t2 = NULL,* pos;
	int m = 0;
	for(pos = head;pos != NULL;pos = pos->next)
	if(pos->item.name == x) m = 1;
	if(m == 0)
	{
		printf("not founded\n");
		return;
	}
	while(t1 != NULL)
	{
		t2 = t1;t2 = t1->next;
		if(t2->item.name == x)
		{
			t1->next = t2->next;
			free(t2);
			break;
		}
		t1 = t1->next;
	}
}

void Show2()
{
	printf("menu:t1.Show1 t2.Put into warehouse t3.Get item from warehouse t4.exit program");
	printf("your choice is:");
}
int main()
{
	Pre();
	while(1)
	{
		Show2();
		int n;
		scanf("%d",&n);
		switch(n)
		{
			case 1:Show1();
			break;
			case 2:
				{
					printf("please input the number and quantity:\n");
					int n,s;
					scanf("%d %d",&n,&s);
					Add(n,s);
					break;
				}
			case 3:
				{
					printf("enter the number you want to remove:\n");
					int n;
					scanf("%d",&n);
					Delet(n);
					break;
				}
			case 4:return 0;
			break;
		}
		printf("any key");
		while(!kbhit());
		system("cls");
	}
	return 0;
}
