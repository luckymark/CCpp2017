/*在main函数中创建一个单向链表；
遍历该链表，依次现实各节点的value；
将该链表所有节点反序；
在该链表中查找第一个值为5的节点，如果找到则返回该节点的序号，否则返回－1；
查找下一个值为5的节点，返回值同上；*/ 
#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct stNode)

struct stNode
{	int num;
	int value;
	struct stNode* next;
};

int n;

void print(struct stNode* head)
{
	struct stNode* p;
	printf("\n Now,These %d records are:\n",n);
	p = head;
	if(head != NULL)
	do
	{
		printf("%d\n",p->value);
		p = p->next;
	}while (p != NULL);
}

void print2(struct stNode* head)
{
	struct stNode* p;
	printf("\n Now,These %d records are:\n",n);
	p = head;
	if(head != NULL)
	do
	{
		if(p->value == 5){
			printf("%d\n",p->num);//change2
		}else{
			printf("-1\n");
		}
		p = p->next;
	}while (p != NULL);
}

struct stNode* creat(void)
{
	struct stNode* head = (struct stNode*) malloc(LEN);
	struct stNode* p1,* p2 = (struct stNode*) malloc(LEN);
	n=0;
	scanf("%d",&p1->value);
	head = NULL;
	while(p1->value != 0)
	{
		n++;
		p1->num=n;//change1
		if(n == 1) head = p1;
		else p2->next = p1;
		p2 = p1;
		p1 = (struct stNode*) malloc(LEN);
		scanf("%d",&p1->value);
	}
	p2->next = NULL;
	return (head);
	
}

struct stNode* ReverList(stNode* head)
{
	stNode* current,* p;
	if(head == NULL)
	{
		return head;
	}
	current = head->next;
	current->next = p->next;
	p->next = head->next;
	head->next = p;
}
int main()
{
	struct stNode* head;
	head = creat();
	struct stNode* ReverList(stNode* head);
	print2(head);
	return 0;
}
