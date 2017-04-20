// Goldbach.cpp
//

#include "stdafx.h"
/* code: 	Goldbach (change from lvl1_5)
 * author:	Kyrios0
 * date: 	2017.02.26
 * state: 	finished
 * version: 1.0.1
 */

#include<stdio.h>
#include<stdlib.h>//malloc()
#include<string.h>
#include<Windows.h>

typedef struct linked {
	int data;
	linked *next;
}linked;

linked* creat(int length)
{
	linked *head, *tail, *p;
	int x;
	head = tail = NULL;

	for (x = 0; x < length; x++)
	{
		p = (linked *)malloc(sizeof(linked));
		p->data = x + 2;//0 and 1 aren't prime or composite number
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



int main(int argc, char** argv)
{
	long len = 1000000;//about 8min
	int primeList[80000];
	linked *current, *head, *temp, *currentHead;
	current = creat(len);
	head = current;
	currentHead = head;

	puts("Working...");
	
	for (long i = 0; ; i++)
	{
		if (i * i >= len)//Termination
		{
			break;
		}

		while (current->next != NULL)
		{
			temp = current->next;

			while (temp->data % currentHead->data == 0)//Delete this number
			{
				current->next = temp->next;
				temp = temp->next;
				len--;
				if (temp == NULL)
				{
					break;
				}
			}

			if (current->next == NULL)
			{
				break;
			}
			else
			{
				current = current->next;
			}
		}

		currentHead = currentHead->next;
		current = currentHead;
	}

	FILE *fpt;
	fpt = fopen("Goldbach.txt", "w");
	puts("Start writing... Please wait a moment.");

	for (int i = 0; i < len; i++)//output
	{
		primeList[i] = head->data;//printf("%d, ", head->data);
		head = head->next;
	}

	int x = 0, y = 0;
	for (int i = 4; i <= 1000000;)
	{
		if (primeList[x] < i - 300)//The speed can be increased by 40% if i == 100,000
		{
			x++;
		}
		if (i - primeList[x] != primeList[y])
		{
			x++;
			if (primeList[x] > 1000000)
			{
				x = 0;
				y++;
			}
		}
		else
		{		
			fprintf(fpt, "%d = %d + %d\n", i, primeList[x], primeList[y]);//printf("%d = %d + %d\n", i, primeList[x], primeList[y]);
			if (i % 20000 == 0)
			{
				printf("%d lines has been writen.\n", i / 2);
			}
			x = 0; y = 0, i += 2;
			continue;
		}
	}

	puts("DONE!");

	system("pause");

	return 0;
}