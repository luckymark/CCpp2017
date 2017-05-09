#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	struct Node *next;
}Node;

Node *initList(Node **pHead);  //��ʼ������ 
Node *creatList(Node **pHead); //�������� 
void printList(Node *pHead);  //��ӡ���� 
Node *invert(Node*pHead);  //������������������ͷָ�� 
int find(Node *pHead,int begin, int target);  //Ѱ��ָ��value�Ľڵ㣬���ؽڵ����   

int main()
{
	Node *myList=NULL;
	initList(&myList);
	creatList(&myList);
	printList(myList);
	myList=invert(myList);
	printList(myList);

	int i;
	i=find(myList,0,5);
	while(i != -1) 
	{
		printf("�ڵ����Ϊ��%d\n",i);
		i=find(myList,i+1,5);
	}
	
	
	
} 

Node *initList(Node **pHead)
{
	*pHead=NULL;
	printf("��ʼ���ɹ���\n");
}

Node *creatList(Node **pHead)
{
	Node *cur;
	Node *pre;
	int n;
	
	printf("������ڵ�����\n");
	scanf("%d",&n); 
	
	pre=cur=(Node*)malloc(sizeof(Node));
	if(cur==NULL)
	{
		printf("�ڴ����ʧ��!\n");
		return *pHead; 
	}
	*pHead=cur;
	cur->next=NULL;
	
	scanf("%d", &cur->value);
	n--;
	while(n--)
	{
		cur=(Node *)malloc(sizeof(Node));
		if(cur==NULL)
		{
			printf("�ڴ����ʧ��!\n");
			return *pHead; 
		}
		pre->next=cur;
		scanf("%d",&cur->value);
		cur->next=NULL;
		pre=cur;
	}
	
	printf("�������ɹ���\n");
	return *pHead;  
}

void printList(Node *pHead)
{
	if(pHead==NULL)
	{
		printf("����Ϊ�գ�\n");
		return;
	}
	Node *cur;
	cur=pHead;
	printf("%d\n",cur->value);
	while(cur->next!=NULL)
	{
		cur=cur->next;
		printf("%d\n",cur->value);
	}
	return;
}

Node *invert(Node* pHead)
{
	Node *cur,*pre,*temp;
	cur=pHead;
	pre=NULL;
	while(cur != NULL)
	{
		temp=cur->next;
		cur->next=pre;
		pre=cur;
		cur=temp;
	}
	printf("������ɹ���\n");
	return pre;
	
}

int find(Node* pHead,int begin, int target)
{
	int index=begin;
	Node *cur;
	cur=pHead;
	for(int i=0;i<begin;i++)
	{
		cur=cur->next;
	}
	while(cur!=NULL && cur->value!=target )
	{
		index++;
		cur=cur->next;
	}
	return cur==NULL? -1:index;
}




