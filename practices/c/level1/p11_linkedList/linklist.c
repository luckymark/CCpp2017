#include<stdio.h>
#include<stdlib.h>




 

typedef struct tempname//结构 part构造 
{
	int num;
	struct tempname *next;
}part;


void creatlb(part** nd)//初始化链表头 
{
	*nd=NULL;
}

void toucha(part** head,part* new_part,int value)
{
	new_part->num=value;
	new_part->next=*head;
	*head=new_part;
}

void weicha(part** head,part* new_part,int value)//尾插   
{
	part* cp=*head;//遍历指针
	new_part->num=value; 
	if(*head==NULL)//如果为空 
	{
		*head=new_part;//我将头指针指向new part部分
		new_part->next=NULL;//将newpart作为后部分 
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
	part* cp=*head1;//遍历指针在原链表开头处 
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
	part* head2;//反序
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

