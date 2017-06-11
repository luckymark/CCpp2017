#include "stdafx.h"

#include "stdlib.h"   

#define LEN sizeof(struct student)  

struct student
{
	int num;              //学号   
	float value;          //分数，其他信息可以继续在下面增加字段  
	struct student *next;       //指向下一节点的指针  
};

int n;
int a[100] = { 0 };

struct student *Create()
{
	struct student *head;       //头节点  
	struct student *p1 = NULL;  //p1保存创建的新节点的地址  
	struct student *p2 = NULL;  //p2保存原链表最后一个节点的地址  

	n = 0;          //创建前链表的节点总数为0：空链表  
	p1 = (struct student *) malloc(LEN);   //开辟一个新节点  
	p2 = p1;            //如果节点开辟成功，则p2先把它的指针保存下来以备后用  

	if (p1 == NULL)        //节点开辟不成功  
	{
		printf("\nCann't create it, try it again in a moment!\n");
		return NULL;
	}
	else                //节点开辟成功  
	{
		head = NULL;        //开始head指向NULL  
		printf("Please input %d node -- num,value: ", n + 1);
		scanf("%d %f", &(p1->num), &(p1->value));    //录入数据  
	}
	while (p1->num != 0)      //只要学号不为0，就继续录入下一个节点  
	{
		n += 1;         //节点总数增加1个  
		if (n == 1)      //如果节点总数是1，则head指向刚创建的节点p1  
		{
			head = p1;
			p2->next = NULL;  //此时的p2就是p1,也就是p1->next指向NULL。  
		}
		else
		{
			p2->next = p1;   //指向上次下面刚刚开辟的新节点  
		}

		p2 = p1;            //把p1的地址给p2保留，然后p1产生新的节点  

		p1 = (struct student *) malloc(LEN);
		printf("Please input %d node -- num,value: ", n + 1);
		scanf("%d %f", &(p1->num), &(p1->value));
	}
	p2->next = NULL;     //此句就是根据单向链表的最后一个节点要指向NULL  

	free(p1);           //p1->num为0的时候跳出了while循环，并且释放p1  
	p1 = NULL;          //特别不要忘记把释放的变量清空置为NULL,否则就变成"野指针"，即地址不确定的指针  
	return head;        //返回创建链表的头指针   
}

struct student *reverse(struct student *head)
{
	struct student *p;      //临时存储  
	struct student *p1;     //存储返回结果  
	struct student *p2;     //源结果节点一个一个取  

	p1 = NULL;          //开始颠倒时，已颠倒的部分为空  
	p2 = head;          //p2指向链表的头节点  
	while (p2 != NULL)
	{
		p = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p;
	}
	head = p1;
	return head;
}

void search(int n,struct student *head)
{
	struct student *p1=head;
	struct student *p2=head;
	struct student *p;
	int tot = 0;
	while (p1!=NULL)
	{
		if (p1->value == n)
		{
			a[tot++]= p1->num;
		}
		p = p1;
		p2 = p;
		p1 = p2->next;
	}
	a[tot]=-1;
}
int main(int argc, char *argv[])
{
	struct student *head;
	printf("Take turns to input the value\nIf you want to stop,input 0 0\n");
	head = Create();
	int judge;
	while (1)
	{
		a[100] = { 0 };
		int judge2 = 0, i = 0, number = 0;
		printf("What do you what to do?\n1:Reverse  2:Search  -1:quit\n");
		scanf("%d", &judge);
		if (judge == 1)
		{
			head=reverse(head);
			printf("Operation succeeded!");
		}
		else if (judge == 2)
		{
			printf("Input the number you want to search\n");
			scanf("%d", &number);
			search(number, head);
			while (a[i] != -1&&a[i]!=0)
			{
				printf("No.%d's value is %d\n", a[i], number);
				++i;
				judge2 = 1;
			}
			if (judge2 == 0)
			{
				printf("-1\nComplete\n");
			}
			else
			{
				printf("Complete\n");
			}
		}
		else if (judge == -1)
		{
			return 0;
		}
		else
		{
			printf("Input Error!\nPlease input again!\n");
		}
	}
	return 0;
}