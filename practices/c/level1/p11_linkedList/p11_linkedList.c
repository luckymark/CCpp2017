#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int a[50] = {0};

struct list
{
	int data;
	struct list *next;
};
typedef struct  list NODE;

struct list *create()
{
	NODE *head, *tail, *pnew;
	int data;
	head = (NODE *)malloc(sizeof(NODE)); //创建头节点 
	if(head == NULL)
	{
		printf("Create linkedlist fail.");
		return NULL;
	}
	head->next = NULL; //头节点指针为NULL 
	tail = head;  //尾指针指向头节点
	printf("Plz enter soma data, enter q to finish:");
	while(scanf("%d", &data) == 1)
	{
		pnew = (NODE *)malloc(sizeof(NODE));
		if(pnew ==NULL)
		{    
			printf("Create linkedlist fail.");
			return NULL;
		}
		pnew->data = data;  //新节点数据域存放数据 
		pnew->next = NULL;  //新节点指针域为NULL 
		tail->next = pnew;  //新节点插入到链表尾部 
		tail = pnew;  //尾指针指向当前的尾节点 
	}
	return head; 
}

void display(NODE *head)
{
	NODE *p;
	for(p = head->next; p != NULL; p = p->next)
		printf("%d ", p->data);
	printf("\n");
}

void reverse(NODE *p)
{
    if(p->next != NULL)
        reverse(p->next);
    printf("%d ", p->data);
}

int search_1(NODE *head)
{
    NODE *p = head;
    int i = 0, j = 0;
    while(p != NULL)
    {
        if(p->data == 5)
        {
            a[j++] = i;
        }
        i++;
        p = p->next;
    }
    return j;
}

void search_2(NODE *head)
{
    int n = search_1(head);
    if(n != 0)
    {
        printf("The NO of each node that values 5 is:\n");
        for(int i = 0; i < n; i++)
            printf("%2d", a[i]);
    }
    else
    printf("-1");
}

int main(int argc, char *argv[])
{
	struct list *head, *pnew;
	head = create();
	if(head == NULL)
		return 0;
	printf("Show the value:\n");
	display(head);
	printf("Reverse the value:\n");
	reverse(head->next);
	printf("\nFind the node that values 5:\n");
	search_2(head);
	pnew = (NODE *)malloc(sizeof(NODE));
	if(pnew == NULL)
	{
		printf("Create linkedlist fail.");
		return 0;
	}
	return 0;
}
