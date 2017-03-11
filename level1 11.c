#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int value = 0;
	node* next=NULL;
}node;
void print_list(node*head,int num);
void input_list(node*head, int num);
node* reverse(node*head, int num);
int find_five(node*head,int num,int flag);
int main()
{
	node *head=NULL, *p, *q,*tail;
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		p = (node*)malloc(sizeof(node));
		if (head == NULL)
		{
			head = p;		
		}
		else
		{
			q->next = p;			
		}
		q = p;
	}

	node *seek = head;
	input_list(head, num);
	print_list(head, num);
	head=reverse(head, num);
	print_list(head, num);

	int position1=find_five(head, num,0);
	printf("position:%d\n", position1);

	int position2 = find_five(head, num, 1);
	printf("position:%d\n", position2);
	system("pause");
    return 0;
}

void init_list(node*head, int num)
{

}
int find_five(node*head,int num,int flag)
{
	
    node *seek = head;
	int mark = 0;
	for (int i = 0; i < num; i++)
	{
		if (seek->value == 5 )
		{			
			if (mark == flag)
			{
				return i;
			}
			mark++;
		}
		seek = seek->next;
	}
	return -1;
}

void print_list(node*head, int num)
{
	node *seek = head;
	for (int i = 0; i < num; i++)
	{
		printf("%d ", seek->value);
		seek = seek->next;
	}
	printf("\n");
}

void input_list(node*head, int num)
{
	node *seek = head;
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &(seek->value));
		seek = seek->next;
	}
}

node* reverse(node*head, int num)
{
	node *seek = head;
	node *former = head, *latter;
	for (int i = 0;; i++)
	{
		if (seek == head)
		{
			seek = seek->next;
			continue;
		}
		latter = seek->next;
		seek->next = former;
		former = seek;
		seek = latter;
		if (i == num - 1)
		{
			head = former;
			break;
		}
	}
	return head;
}
