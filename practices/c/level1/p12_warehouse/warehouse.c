#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
// 目前该程序还无法正常运行，debug了一周了，总是调试正常，运行出错。。。 
typedef struct goods
{
	char name[16],size[4];
	long long int amount;
	struct goods * next;
}GOODS;

void menu(GOODS * Goods,int * n);
void write(GOODS * Goods,int n);
void display(GOODS * Goods);
void input(GOODS * Goods,int * n);
void output(GOODS * Goods,int * n);
long long int is_num(void);
GOODS * move(GOODS * Goods,int n); 
void add(GOODS** head,char * ch1,long long int n,char * ch2);

int main(void)
{
	FILE *fp;
	int max,i;
	
	fp=fopen("warehouse.txt","r");
	fscanf(fp,"%d\n",&max);
	
	GOODS * list, * head, * q;
	head=NULL;
	q=(GOODS *)malloc(sizeof(GOODS *));
	list=(GOODS *)malloc(sizeof(GOODS *));
	for(i=0;i<max;i++)
	{

		if(0==i)
		{
			head=list;
			
		}
		else
		{
			list->next=q;
			list=q;
		}
		fscanf(fp,"%s\n",(list->name));
		system("pause");
		fscanf(fp,"%lld\n",&(list->amount));
		
		fscanf(fp,"%s\n",(list->size));
		
		q=(GOODS *)malloc(sizeof(GOODS *));
		
		
	}
	
	if(NULL!=head)
	{
		list->next=NULL;
	}
	
	free(q);
	q=NULL;
	fclose(fp);

	menu(head,&max);
	
	return 0;
}
void menu(GOODS * Goods,int * n)
{
	char judge;

	do
	{
		system("cls");
		printf("Welcome to warehouse!\n");
		printf("What do you want to do\n");
		printf("2.display\t3.input\n");
		printf("4.output\t 5.quit\n");
		judge=getch();
		switch(judge)
		{
			case '2':
				display(Goods);
				system("pause");
				break;
			case '3':
				input(Goods,n);
				break;
			case '4':
				output(Goods,n);
				break;
			case '5':
				return;
			default:
				printf("Please enter a right number\n");
				system("pause");
		}
		write(Goods,*n);
	}while(judge!='5');
}
void display(GOODS * Goods)
{
	GOODS * cp;
	int i=0;
	
	cp=Goods;
	system("cls");
	while(NULL!=cp)
	{
		printf("%d.%15s:%d\tSize:%c\n",i+1,cp->name,cp->amount,cp->size);
		cp=cp->next;
		i++;
	}
	
	return;
}
void write(GOODS * Goods,int n)
{
	FILE * fp;
	GOODS * cp;
	
	cp=Goods;
	fp=fopen("warehouse.txt","w");
	fprintf(fp,"%d\n",n);
	while(cp!=NULL)
	{
		fprintf(fp,"%s\n",cp->name);
		fprintf(fp,"%lld\n",cp->amount);
		fprintf(fp,"%s\n",cp->size);
		cp=cp->next;
	}
	fclose(fp);
}
void input(GOODS * Goods,int * n)
{
	int judge;
	GOODS * cp, * q;
	char Name[16],Size[4];
	long long int Amount;
	
		
	do
	{
		display(Goods);
		printf("Which do you want to input?(enter the number)\n");
		printf("0 to quit\n");
		if(1==scanf("%d",&judge))
		{
			fflush(stdin);
			if(0==judge)return;
			cp=move(Goods,judge);
			if(NULL==cp)
			{
				
				printf("Do you want to add a kind of new goods?(y to continue)\n");
				if(getch()=='y')
				{
					printf("Please enter the name:(in 15 words)\n");
					fgets(Name,15,stdin);
					printf("Please enter the amount\n");
					Amount=is_num();
					printf("Please enter the size(s/m/l)\n");
					fflush(stdin);
					fgets(Size,4,stdin);
					add(&cp,Name,Amount,Size);
					if(NULL==Goods)
					{
						Goods=cp;
					}
					
				}
				*n=*n+1;
				
			}
			else
			{
				printf("How many %s do you want?\n",cp->name);
				cp->amount=cp->amount+is_num();
			}
		}
		
	}while(0!=judge);
	

}
void output(GOODS * Goods,int * n)
{
	int judge;
	GOODS * cp;
	long long int delta;
	
	do
	{
		display(Goods);
		printf("Which do you want to output?(enter the number)\n");
		printf("0 to quit\n");
		fflush(stdin);
		if(1==scanf("%d",&judge))
		{
			fflush(stdin);
			if(0==judge)return;
			cp=move(Goods,judge);
			if(NULL==cp)
			{	
				printf("Error!\n");
				system("pause");
			}
			else
			{
				printf("How many %s do you want?\n",cp->name);
				delta=is_num();
				if(delta<=cp->amount)
				{
					cp->amount=cp->amount-delta;
				}
				else
				{
					printf("Error!\n");
					system("pause");
				}
			}
		}
		
	}while(0!=judge);
}
long long int is_num(void)
{
	long long int n;
	int right;
	

	right=scanf("%lld",&n);
	while(0==right)
	{
		printf("Error,please enter again.\n");
		fflush(stdin);
		right=scanf("%lld",&n);
	}
	
	if(n>=0)return n;
	else return 0;
}
GOODS * move(GOODS * Goods,int n)
{
	GOODS * cp;
	int i;
	
	cp=Goods;
	for(i=0;i<n-1;i++)
	{
		if(NULL==cp)
		{
			return NULL;
		}
		cp=cp->next;
	}
	
	return cp;
}
void add(GOODS** head,char * ch1,long long int n,char ch2[4])
{
	GOODS * cp;
	
	cp=(GOODS *)malloc(sizeof(GOODS *));
	if(NULL==*head)
	{
		*head=cp;
		cp->next=NULL;
	}
	else
	{
		cp->next=(*head)->next;
		(*head)->next=cp;
	}
	for(int i=0;ch1[i]!='\0';i++)
	{
		if(ch1[i]!='\n')
		{
			(cp->name)[i]=ch1[i];
		}
		else
		{
			(cp->name)[i]='\0';
		}
	}
	cp->amount=n;
	for(int i=0;ch2[i]!='\0';i++)
	{
		if(ch2[i]!='\n')
		{
			(cp->size)[i]=ch2[i];
		}
		else
		{
			(cp->size)[i]='\0';
		}
	}

}
