/* code:	Linked list Step1
 * author:	Kyrios0
 * date: 	2017.03.09
 * state: 	unfinished
 * version: 1.0.2
 */

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<conio.h>

typedef struct linked {
	int data;
	linked *next;
}linked;

linked *head, *tail;

linked* creat(int length)
{
	linked *p;
	int x;
	head = tail = NULL;

	for (x = 0; x < length; x++)
	{
		p = (linked *)malloc(sizeof(linked));
		p->data = x + 2;
		p->next = NULL;

		if (head == NULL)
		{
			head = tail = p;
		}
		else
		{
			tail = tail->next = p;
		}
	}
	return head;
}

int reverseL()
{
	linked *currentHead = head, *temp = head->next, *currentTail;
	currentHead->next = NULL; currentTail = temp->next;

	while (currentTail->next != NULL)
	{
		if (temp != tail)
		{
			currentTail = temp->next;
		}
		temp->next = currentHead;
		currentHead = temp;
		temp = currentTail;
	}
	temp->next = currentHead;
	currentHead = temp;
	temp = currentTail;

	temp = head;
	head = tail;
	tail = head;
	return 0;
}

int main(int argc, char** argv)
{
	int len = 10;
	creat(len);
	linked *currentHead = head, *currentTail = tail;

	printf("Before:\t");
	for (int i = 0; i < len; i++)//output
	{
		printf("%d, ", currentHead->data);
		currentHead = currentHead->next;
	}
	printf("\n");

	reverseL();

	currentHead = head, currentTail = tail;
	printf("After:\t");
	for (int i = 0; i < len; i++)//output
	{
		printf("%d, ", currentHead->data);
		currentHead = currentHead->next;		
	}
	printf("\n");

	currentHead = head, currentTail = tail;
	int state = 0;
	for (int i = 0; i < len; i++)
	{
		if (currentHead->data == 5)
		{
			printf("Node%d : 5\n", i+1);
			state = 1;
		}
		currentHead = currentHead->next;
	}
	if (state == 0)
	{
		puts("5 not find: -1");
	}
	_getch();
    return 0;
}

