// LinkList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

void InitialList();
void InputList();
void PushList(int x);
void DisplayList();
void ReverseList();
void FindList(int x);

struct Node
{
	int value = 0;
	struct Node * next;
}*phead,*pcurrent;

int main()
{
	InitialList();
	InputList();

	while (1)
	{
		printf("请输入您要进行的操作编号：\n");
		printf(" 1.遍历该链表\n 2.将该链表节点反序\n 3.查找链表元素并返回其当前位置\n 0.退出\n");
		int i;
		scanf("%d", &i);
		switch (i)
		{
		case 0 :
			exit(1);
			break;
		case 1 :
			DisplayList();
			break;
		case 2 :
			ReverseList();
			break;
		case 3 :
			printf("请输入您要查找的元素：\n");
			int x;
			scanf("%d", &x);
			FindList(x);
			break;
		default:
			break;
		}
	}
    return 0;
}


void InitialList()
{
	phead = (struct Node*)malloc(sizeof(struct Node));
	phead->next = NULL;
	pcurrent = (struct Node *)malloc(sizeof(struct Node));
	pcurrent->next = NULL;
}

void InputList()
{
	printf("请输入链表元素个数：\n");
	int n;
	scanf("%d", &n);
	printf("请输入元素值：\n");
	int x;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &x);
		PushList(x);
	}
}

void PushList(int x)
{
	struct Node *p;
	p = (struct Node*)malloc(sizeof(struct Node));
	p->value = x;
	p->next = NULL;
	if (phead->next == NULL)
	{
		phead->next = p;
		pcurrent = p;
		return;
	}
	pcurrent->next = p;
	pcurrent = p;
}

void DisplayList()
{
	struct Node *cp;
	cp = phead->next;
	while (cp != NULL)
	{
		printf("%d\t", cp->value);
		cp = cp->next;
	}
	printf("\n");
}

void ReverseList()
{
	struct Node *pPrev, *pNext, *p;
	p = phead->next;
	pcurrent = p;
	pPrev = NULL;
	while (p != NULL)
	{
		pNext = p->next;
		p->next = pPrev;
		pPrev = p;
		p = pNext;
	}
	phead->next = pPrev;
}

void FindList(int x)
{
	int k = 1;
	int find = 0;
	struct Node *p;
	p = phead->next;
	while (p != NULL)
	{
		if (p->value == x)
		{
			find = 1;
			printf("%d", k);
		}
		p = p->next;
		k++;
	}
	if (!find)
	{
		printf("-1");
	}
	printf("\n");
}
