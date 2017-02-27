// isPrime.cpp
//

#include "stdafx.h"
/* code:	Linked list Step0 for eratosthenes Prime (change from lvl1_5)
 * author:	Kyrios0
 * date: 	2017.02.21
 * state: 	finished
 * version: 1.0.2
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
	long len, userNumber, finalNumber = 2;

	puts("Prime Number Detection System");
	puts("Please enter the number you want to detect（It should be no less than 2）");
	scanf("%ld", &userNumber);

	len = userNumber;
	linked *current, *head, *temp, *currenthead;
	current = creat(len);
	head = current;
	currenthead = head;

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

			while (temp->data % currenthead->data == 0)//Delete this number
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

		finalNumber = current->data;
		currenthead = currenthead->next;
		current = currenthead;
	}

	printf(((finalNumber == userNumber) || (userNumber == 2)) ? ("%d is a prime number\n") : ("%d is a composite number\n"), userNumber);

	system("pause");

	return 0;
}