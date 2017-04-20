// house.c
//
/*	author:	Kyrios0
 *	date:	2017.03.23
 *	version:1.0.6
 *	state:	list unfinished//strlen * ' '
 *			pop  unfinished//number
 */
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<conio.h>
FILE* fp = fopen("house.txt", "r+");

typedef struct list {
	int data;
	char name[128];
	list *next;
}list;

list *head = NULL, *currentTail = NULL;

list* getList()
{
	list *tail, *p;
	char *state;
	
	p = (list *)malloc(sizeof(list));
	while (!feof(fp))
	{		
		state = fgets(p->name, 128, fp);
		if (state == NULL)//for empty list
		{
			return head;
		}
		p->name[strlen(p->name) - 1] = '\0';
		fscanf(fp, "%d", &p->data);
		fgetc(fp);
		p->next = NULL;
		tail = p;
		if (head->next == NULL)
		{
			head->next = tail;
		}
		p = (list *)malloc(sizeof(list));
		tail->next = p;
	}
	free(p);
	p = NULL;
	tail->next = NULL;
	return tail;
}

void help()
{
	puts("\n\tGNU bash, Version 4.3.42(1)-release (x86_64-pc-kyrinux-gnu)\n\n\
			\tCommand\t\tInfo\n\
			\tlist\t\tView\n\
			\tpush\t\tWrite\n\
			\tpop\t\tDelete\n\
			\tquit\t\tQuit\n");
}

int pop()
{	
	list *p = head->next, *prev = NULL;
	if (p == NULL)//for empty list
	{
		puts("ERROR: The list is empty!");
		return -1;
	}
	puts("Which one do you want to remove?");
	int i = 1, j = 1, popN;
	while (p->next != NULL)
	{
		printf("%d:%s\n", i, p->name);
		p = p->next;
		i++;
	}
	/*if (i == 1)
	{
		strcpy(p->name, "Empty");//p->name = "Empty";
	}*/
	printf("%d:%s\n", i, p->name);
	while (1)//filter
	{
		printf("Please enter the serial number(1-%d)(Enter 0 to exit pop):", i);
		scanf("%d", &popN);
		getchar();
		if (popN == 0)
		{
			return 1;
		}
		if (popN >= 1 && popN <= i)
		{
			break;
		}
		puts("Invaild serial number");
	}
	
	p = head->next;
	while (j < popN)
	{
		prev = p;
		p = p->next;
		j++;
	}
	printf("%d:%s\n", j, p->name);
	if (popN == 1)
	{
		head = head->next;
	}
	else
	{
		if (popN == i)
		{
			currentTail = prev;
			currentTail->next = NULL;
		}
		else
		{
			prev->next = p->next;
		}
	}
	puts("You poped it!");
	return 0;

}

int allList()
{
	list *p = head->next;
	if (p == NULL)//for empty list
	{
		puts("\n\tEMPTY\n");
		return -1;
	}
	printf("\n\tName\t\tAmount\n");
	while (p->next != NULL)
	{
		printf("\t%s\t\t%5d\n", p->name, p->data);
		p = p->next;
	}
	printf("\t%s\t\t%5d\n\n", p->name, p->data);
	return 0;
}

void invalid(char *cm)
{
	cm[strlen(cm) - 1] = '\0';
	printf("\"%s\" isn't a valid command, Type \"help\" for more information.\n", cm);
}

int push()
{
	list *p;
	char yn;
	while (1)
	{
		p = (list *)malloc(sizeof(list));
		p->next = NULL;
		printf("Please enter name: ");
		fgets(p->name, 128, stdin);
		p->name[strlen(p->name) - 1] = '\0';
		printf("Please enter amount:¡¡");
		scanf_s("%d", &p->data);
		getchar();
		if (p->data <= 0)
		{
			puts("ERROR: The number of items must be greater than zero.");
			free(p);
			return -1;
		}
		printf("\"%s\" has been added. Would you like to continue to push?(y/n)", p->name);
		currentTail->next = p;
		currentTail = p;
		yn = getchar();
		getchar();
		while (yn != 'n' && yn != 'y')
		{
			printf("\"%s\" has been added. Would you like to continue to push?(y/n)", p->name);
			yn = getchar();
			getchar();
		}
		if (yn == 'n')
		{
			break;
		}
	}
	return 0;
}

int saveData()
{
	FILE* fpw = fopen("house.txt", "w+");
	list *p = head->next;
	if (p == NULL)//for empty list
	{
		return -1;
	}
	while (p->next != NULL)
	{
		fprintf(fpw, "%s\n%d\n", p->name, p->data);
		p = p->next;
	}

	fprintf(fpw, "%s\n%d", p->name, p->data);
	return 0;
}

int main(int argc, char **argv)
{
	char cm[128] = "Kyrios";
	puts("Kyrinux 1.0.0 (default, Mar 10 2017, 11:07:07) [MSC v.1500 64 bit (AMD64)] on win64");
	puts("Type \"help\" for more information.");

	head = (list *)malloc(sizeof(list));
	head->next = NULL;
	currentTail = getList();
	while (1)
	{
		printf("root@user: ");
		fgets(cm, 128, stdin);
		if (!strcmp(cm, "help\n"))
		{
			help();
		}
		else if (!strcmp(cm, "push\n"))
		{
			push();
		}
		else if (!strcmp(cm, "pop\n"))
		{
			pop();
		}
		else if (!strcmp(cm, "list\n"))
		{
			allList();
		}
		else if (!strcmp(cm, "quit\n"))
		{
			break;
		}
		else
		{
			invalid(cm);
		}
		
	}
	saveData();
	puts("Kyrios hope you'll have a nice day, bye.");
	puts("Press any key to quit...");
	_getch();
    return 0;
}

