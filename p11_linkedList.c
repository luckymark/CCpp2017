#include<stdio.h>
#include<stdlib.h>

void turn(struct node* pt);
void AddValue(struct node* pt ,int n);
void AddNode(struct queue* pq);
void InitializeQueue(struct queue* pq);
int find(struct node* pt, int n, int* pn);

typedef struct node
{
	int value;
	struct node* next;
}Node;

 typedef struct queue
{
	 struct node* front;
	struct node* rear;
}Queue;

Queue queue;

void main()
{


	int lens;
	int value;
	int* locat;

	printf("enter a number to determine the lens of your link:");
	scanf_s("%d", &lens);

	InitializeQueue(&queue);
	locat = (int*)malloc(sizeof(int)*lens);

	for (int i = 0; i <lens; i++)
	{
		AddNode(&queue);
	}

	for ( struct node* pt=queue.front; pt!=NULL;pt=pt->next)
	{ 
		printf("enter the value for node:");
		scanf_s("%d", &value);
		AddValue(pt,value);
	}

	system("pause");
	turn(queue.front);
	printf("turn:\n");

	for (struct node* pt = queue.front; pt != NULL; pt = pt->next)
	{
		printf(" the value of node %d \n", pt->value);

	}

	find(queue.front,lens,locat);

	for (int i = 0; i < lens; i++)
		printf("%d\n", locat[i]);

	system("pause");
}

void InitializeQueue(struct queue* pq)
{
	pq->front = pq->rear = NULL;
}
void AddNode(struct queue* pq)
{
	Node* pt = (Node*)malloc(sizeof(Node));
	if (pq->front == NULL)
		pq->front = pt;
	else
		pq->rear->next = pt;
	pq->rear= pt;
	pt->next = NULL; 

}
void AddValue(struct node* pt, int n)
{
	pt->value = n;
}
void turn( struct node* pt)
{
	
	if (pt->next->next  == NULL)	//最后一层递归因提前跳出故不完整，要用下列语句补充
	{
		pt->next->next = pt;
		queue.front = pt->next;
		return;
	}
	
	turn(pt->next);

	pt->next->next = pt;
	queue.rear = pt;
	pt->next = NULL;
	
}

int find(struct node* pt, int n, int* pn)
{
	int temp = 0;

	for (int i = 0; i < n; i++)
	{
		if (pt->value == 5)
		{
			pn[temp] = pt;
			temp++;
		}
		else
		{
			pn[temp] = -1;
			temp++;
		}
		pt = pt->next;
	}
}