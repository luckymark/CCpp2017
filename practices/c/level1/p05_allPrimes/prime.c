#include<stdio.h>
#include<stdlib.h>
typedef struct link_list
{
	long long int num;
	struct link_list * next;
}LINK;
LINK * create(long long int n);
void dele(LINK * head);
void screen(LINK * head);
void display(LINK * head);
int main(void)
{
	long long int max;
	LINK * _head; 
	scanf("%lld",&max);
	_head=create(max);
	
	//screen(_head);
	display(_head);
	
	system("pause");
	return 0;
}
LINK * create(long long int n)
{
	LINK *head,*cp1,*cp2;
	long long int i;
	
	head=NULL;
	cp1=cp2=(LINK *)malloc(sizeof(LINK *));
	for(i=2;i<=n;i++)
	{
		if(2==i)
		{
			head=cp1;
		}
		else
		{
			cp1->next=cp2;
			cp1=cp2;
		}
		cp1->num=i;
		cp2=(LINK *)malloc(sizeof(LINK *));
	}
	cp1->next=NULL;
	free(cp2);

	return head;
}
void screen(LINK * head)
{
	LINK *cp1,*cp2,*cp3,*temp;
	cp1=cp2=cp3=head;
	while(cp3!=NULL)
	{
		cp2=cp3;
		cp1=cp3;
		while(cp2!=NULL&&cp1!=NULL)
		{
			cp2=cp2->next;
			if(cp2!=NULL&&0==cp2->num%cp3->num)
			{
				temp=cp2;
				cp1->next=cp1->next->next;
				cp2=cp2->next;
			}
			cp1=cp1->next;
		}
		cp3=cp3->next;
	}
}
void display(LINK * head)
{
	LINK *cp;
	
	cp=head;
	while(cp!=NULL)
	{
		printf("%lld\t",cp->num);
		cp=cp->next;
	}
} 
