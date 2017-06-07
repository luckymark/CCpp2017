// LinkList.cpp : �������̨Ӧ�ó������ڵ㡣
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
		printf("��������Ҫ���еĲ�����ţ�\n");
		printf(" 1.����������\n 2.��������ڵ㷴��\n 3.��������Ԫ�ز������䵱ǰλ��\n 0.�˳�\n");
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
			printf("��������Ҫ���ҵ�Ԫ�أ�\n");
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
	printf("����������Ԫ�ظ�����\n");
	int n;
	scanf("%d", &n);
	printf("������Ԫ��ֵ��\n");
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
