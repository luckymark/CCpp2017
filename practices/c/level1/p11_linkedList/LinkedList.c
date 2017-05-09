#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	struct Node *next;
}Node;

Node *initList(Node **pHead);  //初始化链表 
Node *creatList(Node **pHead); //创建链表 
void printList(Node *pHead);  //打印链表 
Node *invert(Node*pHead);  //逆序链表，返回逆序后的头指针 
int find(Node *pHead,int begin, int target);  //寻找指点value的节点，返回节点序号   

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
		printf("节点序号为：%d\n",i);
		i=find(myList,i+1,5);
	}
	
	
	
} 

Node *initList(Node **pHead)
{
	*pHead=NULL;
	printf("初始化成功！\n");
}

Node *creatList(Node **pHead)
{
	Node *cur;
	Node *pre;
	int n;
	
	printf("请输入节点数：\n");
	scanf("%d",&n); 
	
	pre=cur=(Node*)malloc(sizeof(Node));
	if(cur==NULL)
	{
		printf("内存分配失败!\n");
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
			printf("内存分配失败!\n");
			return *pHead; 
		}
		pre->next=cur;
		scanf("%d",&cur->value);
		cur->next=NULL;
		pre=cur;
	}
	
	printf("链表创建成功！\n");
	return *pHead;  
}

void printList(Node *pHead)
{
	if(pHead==NULL)
	{
		printf("链表为空！\n");
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
	printf("链表反序成功！\n");
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




