// warehouse.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef struct Node
{
	char Name[20];
	int Number;
	struct Node*next;
}Node;
typedef Node* List;

List MakeEmpty(void);
void NewNode(List Head, char name[20], int number);
void Display(List Head);
void Input(List Head);
void Output(List Head);

int main(void)
{
	List Head = MakeEmpty();
	char NameOfGood[20];
	int NumberOfGood;

	FILE*fp = fopen("warehouse.txt", "r");
	while (fscanf(fp, "%s%d", &NameOfGood, &NumberOfGood) != EOF)
	{
		NewNode(Head, NameOfGood, NumberOfGood);
	}

	while (1)
	{
		printf("\n您可以进行的操作如下：\n");
		printf(" 1.显示存货列表\n 2.入库\n 3.出库\n 0.退出程序\n");
		printf("请输入您想进行的操作的序号：\n");

		int x;
		scanf("%d", &x);

		switch (x)
		{
		case 0:
			fp = fopen("warehouse.txt", "w");
			for (List P = Head->next; P != NULL; P = P->next)
			{
				fprintf(fp, "%s %d\n", P->Name, P->Number);
			}
			fclose(fp);
			exit(1);
			break;
		case 1:
			Display(Head);
			break;
		case 2:
			Input(Head);
			break;
		case 3:
			Output(Head);
			break;
		default:
			printf("操作错误！请正确输入！\n");
			break;
		}
	}
	return 0;
}

List MakeEmpty(void)
{
	List Head = (Node*)malloc(sizeof(Node));
	Head->next = NULL;
	return Head;
}

void NewNode(List Head, char name[20], int number)
{
	List P = Head;
	while (P->next != NULL)
	{
		P = P->next;
	}
	List Q = (Node*)malloc(sizeof(Node));
	strcpy(Q->Name, name);
	Q->Number = number;
	Q->next = NULL;
	P->next = Q;
}

void Display(List Head)
{
	List P = Head->next;
	while (P != NULL)
	{
		printf("%s %d\n", P->Name, P->Number);
		P = P->next;
	}
	printf("\n");
}

void Input(List Head)
{
	char NameOfGood[20];
	int NumberOfGood;

	printf("请输入货物型号和数量:\n");
	scanf("%s %d", &NameOfGood, &NumberOfGood);
	for (List P = Head->next; P != NULL; P = P->next)
	{
		if (strcmp(NameOfGood, P->Name)==0)
		{
			P->Number += NumberOfGood;
			printf("%s当前数量为%d\n", P->Name, P->Number);
			break;
		}
		if (strcmp(NameOfGood, P->Name) != 0)
		{
			if (P->next == NULL)
			{
				List Q = P->next;
				Q = (Node*)malloc(sizeof(Node));
				strcpy(Q->Name, NameOfGood);
				Q->Number = NumberOfGood;
				Q->next = NULL;
				P->next = Q;
				break;
			}
		}
	}

}

void Output(List Head)
{
	char NameOfGood[20];
	int NumberOfGood;

	printf("请输入货物型号和数量:\n");
	scanf("%s %d", &NameOfGood, &NumberOfGood);
	for (List P = Head->next; P != NULL; P = P->next)
	{
		if (strcmp(NameOfGood, P->Name) == 0)
		{
			if (P->Number - NumberOfGood < 0)
			{
				printf("操作失败！货物数量不足。\n");
			}
			else
			{
				P->Number -= NumberOfGood;
				printf("%s当前数量为%d\n", P->Name, P->Number);
				break;
			}
		}
		if (P->next == NULL&&strcmp(NameOfGood, P->Name) != 0)
		{
			printf("操作失败！库存中没有该货物！\n");
		}
	}
}