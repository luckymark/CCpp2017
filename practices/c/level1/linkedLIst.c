#include <stdio.h>
#include <stdlib.h>

typedef struct slist
{
	int data=0;
	struct slist* next=NULL;
} Node;

void appand(slist* oldnode,slist* newnode);
void show(slist* head);
void remove(slist* beforeremove,slist* remove);
void reverse(Node* head);
int find(Node* head,int value);
int find_second(Node* head,int value,int times);

int main()
{
	Node *head=(Node*)malloc(sizeof(Node));
	head->data=0;
	Node *node1=(Node*)malloc(sizeof(Node));
	node1->data=1;
	Node *node2=(Node*)malloc(sizeof(Node));
	node2->data=2;
	Node *node3=(Node*)malloc(sizeof(Node));
	node3->data=5;
	appand(head,node1);
	appand(node1,node2);
	appand(node2,node3);
	show(head);
	
	remove(node1,node2);
	
	printf("\n%d",find(head,5));
	printf("\n%d",find_second(head,5,2));	
	reverse(head);
	return 0;
}

void appand(slist* oldnode,slist* newnode)
{
	oldnode->next=newnode;
	newnode->next=NULL;
}
void show(slist* head)
{
	while(head)
	{
		printf("->%d",head->data);
		head=head->next;
	}
}
void remove(slist* beforeremove,slist* remove)
{
	beforeremove->next=remove->next;
	free (remove);
}
void reverse(Node* head)
{
	int count=0;
	Node* a=head;
	while (1)
	{
		count++;
		if (a->next==NULL) break;
		a=a->next;
	}
	a=head;
	Node* allNode[count];
	for(int i=0;i<count;i++)
	{
		allNode[i]=a;
		a=a->next;
	}
	for(int i=0;i<count-1;i++)
	{
		allNode[i+1]->next=allNode[i];
	}
	head->next=NULL;
}
int find(Node* head,int value)
{
	Node* a=head;
	int n=0;
	while(1)
	{
		if(a->data==value) return n;
		if(a->next==NULL) return -1;
		a=a->next;
		n++;
	}
}
int find_second(Node* head,int value,int times)
{
	Node* a=head;
	int n=0,m=0;
	while(1)
	{
		if(a->data==value) 
		{
			m++;
			if(m==value) return n;
		}
		if(a->next==NULL) return -1;
		a=a->next;
		n++;
	}
}
