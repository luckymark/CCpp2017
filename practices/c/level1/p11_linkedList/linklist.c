#include<stdio.h>
#include<stdlib.h>




 

typedef struct tempname//�ṹ part���� 
{
	int num;
	struct tempname *next;
}part;


void creatlb(part** nd)//��ʼ������ͷ 
{
	*nd=NULL;
}

void toucha(part** head,part* new_part,int value)
{
	new_part->num=value;
	new_part->next=*head;
	*head=new_part;
}

void weicha(part** head,part* new_part,int value)//β��   
{
	part* cp=*head;//����ָ��
	new_part->num=value; 
	if(*head==NULL)//���Ϊ�� 
	{
		*head=new_part;//�ҽ�ͷָ��ָ��new part����
		new_part->next=NULL;//��newpart��Ϊ�󲿷� 
	}
	else
	{
		while(cp->next!=NULL)
		{
			cp=cp->next;
		}
		cp->next=new_part; 
		new_part->next=NULL;
	} 
}    


void disp(part** head)
{
	part* cp=*head;
	while(cp!=NULL)
	{
		printf("num = %d\n",cp->num);
		cp = cp->next;
	}
}

void change(part** head1,part** head2)
{
	*head2=NULL;
	part* zp=NULL;
	part* cp=*head1;//����ָ����ԭ����ͷ�� 
	while(cp!=NULL)
	{
		zp=(part*)malloc(sizeof(part));
		toucha(head2,zp,cp->num);
		cp = cp->next;
	}
	
}

int find(part** head,int value)
{
	part* cp=*head;
	int i=1;
	int k=0; 
	while(cp!=NULL)
	{
		if((cp->num)==5)
		{
			printf("%d\n",i);
			k++;
		}
		cp=cp->next;
		i++;
	}
	if(k==0)
	{
		printf("-1");
		return -1;
	}
	return 0;
}

int main(void)
{
	part* head1;
	part* head2;//����
	part* xp=NULL;
	creatlb(&head1);
	for(int i=0;i<8;i++)
	{
		xp=(part*)malloc(sizeof(part));
		weicha(&head1,xp,i);
	}
	disp(&head1);
	
	change(&head1,&head2);
	
	disp(&head2);
	
	find(&head1,5);
	
	return 0;
}

