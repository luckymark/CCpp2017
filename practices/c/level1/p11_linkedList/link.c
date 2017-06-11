#include "stdafx.h"

#include "stdlib.h"   

#define LEN sizeof(struct student)  

struct student
{
	int num;              //ѧ��   
	float value;          //������������Ϣ���Լ��������������ֶ�  
	struct student *next;       //ָ����һ�ڵ��ָ��  
};

int n;
int a[100] = { 0 };

struct student *Create()
{
	struct student *head;       //ͷ�ڵ�  
	struct student *p1 = NULL;  //p1���洴�����½ڵ�ĵ�ַ  
	struct student *p2 = NULL;  //p2����ԭ�������һ���ڵ�ĵ�ַ  

	n = 0;          //����ǰ����Ľڵ�����Ϊ0��������  
	p1 = (struct student *) malloc(LEN);   //����һ���½ڵ�  
	p2 = p1;            //����ڵ㿪�ٳɹ�����p2�Ȱ�����ָ�뱣�������Ա�����  

	if (p1 == NULL)        //�ڵ㿪�ٲ��ɹ�  
	{
		printf("\nCann't create it, try it again in a moment!\n");
		return NULL;
	}
	else                //�ڵ㿪�ٳɹ�  
	{
		head = NULL;        //��ʼheadָ��NULL  
		printf("Please input %d node -- num,value: ", n + 1);
		scanf("%d %f", &(p1->num), &(p1->value));    //¼������  
	}
	while (p1->num != 0)      //ֻҪѧ�Ų�Ϊ0���ͼ���¼����һ���ڵ�  
	{
		n += 1;         //�ڵ���������1��  
		if (n == 1)      //����ڵ�������1����headָ��մ����Ľڵ�p1  
		{
			head = p1;
			p2->next = NULL;  //��ʱ��p2����p1,Ҳ����p1->nextָ��NULL��  
		}
		else
		{
			p2->next = p1;   //ָ���ϴ�����ոտ��ٵ��½ڵ�  
		}

		p2 = p1;            //��p1�ĵ�ַ��p2������Ȼ��p1�����µĽڵ�  

		p1 = (struct student *) malloc(LEN);
		printf("Please input %d node -- num,value: ", n + 1);
		scanf("%d %f", &(p1->num), &(p1->value));
	}
	p2->next = NULL;     //�˾���Ǹ��ݵ�����������һ���ڵ�Ҫָ��NULL  

	free(p1);           //p1->numΪ0��ʱ��������whileѭ���������ͷ�p1  
	p1 = NULL;          //�ر�Ҫ���ǰ��ͷŵı��������ΪNULL,����ͱ��"Ұָ��"������ַ��ȷ����ָ��  
	return head;        //���ش��������ͷָ��   
}

struct student *reverse(struct student *head)
{
	struct student *p;      //��ʱ�洢  
	struct student *p1;     //�洢���ؽ��  
	struct student *p2;     //Դ����ڵ�һ��һ��ȡ  

	p1 = NULL;          //��ʼ�ߵ�ʱ���ѵߵ��Ĳ���Ϊ��  
	p2 = head;          //p2ָ�������ͷ�ڵ�  
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