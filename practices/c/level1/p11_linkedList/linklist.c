#include<stdio.h>
#include<malloc.h>

struct node
{
	int value;
	node *pnext;
};

node *create(int);
void print(node*);
void reverse(node*);
void find(node*,int);
void findsec(node*, int);

int main()
{
	node *head = create(10);
	print(head);
	reverse(head);
	print(head);
	printf("After reverse:\n");
	find(head, 5);
	findsec(head, 5);

	return 0;
}

node *create(int length)
{
	node *head = (node*)malloc(sizeof(node));
	head->pnext = NULL;
	node *tail = head;
	node *data;
	for (int i = 0; i < length; i++)
	{
		data = (node*)malloc(sizeof(node));
		data->value = -i*i+8*i-10;
		tail->pnext = data;
		tail = data;
	}
	tail->pnext = NULL;
	return head;
}

void print(node *head)
{
	node *read = head;
	while (read = read->pnext)
	{
		printf("%-4d", read->value);
	}
	printf("\n");
}

void reverse(node *head)
{
	node *pre = head;
	node *now = head->pnext;
	node *next = now->pnext;
	pre = NULL;
	while (next)
	{
		now->pnext = pre;
		pre = now;
		now = next;
		next = next->pnext;
	}
	now->pnext = pre;
	head->pnext = now;
}

void find(node *head, int num)
{
	node *read = head;
	int index=0;
	while (read=read->pnext)
	{
		index++;
		if (read->value == num)
		{
			printf("%d\n", index);
			return;
		}
	}
	printf("-1");
}

void findsec(node *head, int num)
{
	node *read = head;
	int index = 0;
	int found = 0;
	while (read = read->pnext)
	{
		index++;
		if (read->value == num)
		{
			if (found == 0)
			{
				found++;
			}
			else
			{
				printf("%d\n", index);
				return;
			}
			
		}
	}
	printf("-1");
}