#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20

typedef struct node
{
    char name[N];
    int quantity;
    struct node *next;
}Node;

Node *phead;
int quantity;
int n=0;
char name[N];

void init();
void show();
void input();
void output();
void save();

int main(void)
{
    init();
    while(1)
    {
        int choice;
        printf("Please choose which one you want to do:\n1.show\n2.input\n3.output\n4.quit\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            show();
        }
        else if(choice==2)
        {
            input();
        }
        else if(choice==3)
        {
            output();
        }
        else if(choice==4)
        {
            save();
            break;
        }
        else
        {
            printf("Error!Please choose again!\n");
        }
    }
}

void init()
{
    phead=(Node*)malloc(sizeof(Node));
    phead->next=NULL;
    FILE *fp;
    fp=fopen("data.txt","r");
    if(fscanf(fp,"%d",&n) != EOF)
    {
        for(int i=0;i<n;i++)
        {
            fscanf(fp,"%s",name);
            fscanf(fp,"%d",&quantity);
            show();
        }
        fclose(fp);
    }
}

void show()
{
    Node *p;
    p=phead->next;
    if(p==NULL)
    {
        printf("It is empty now!\n");
    }
    while(p!=NULL)
    {
        printf("Name: %s Quantity: %d\n",p->name,p->quantity);
        p=p->next;
    }
}

void input()
{
    int temp=0;
    Node *p;
    p=phead->next;
    printf("Input name.\n");
    scanf("%s",name);
    printf("Input quantity.\n");
    scanf("%d",&quantity);
    while(p!=NULL)
    {
        if(strcmp(p->name,name)==0)
        {
            temp=1;
            p->quantity += quantity;
        }
        p=p->next;
    }

    if(temp==0)
    {
        Node *p;
        p=(Node*)malloc(sizeof(Node));
        strcpy(p -> name,name);
        p -> quantity = quantity;
        p -> next = phead -> next;
        phead -> next = p;
        n++;
    }

}

void output()
{
    int search=0;
    int enough=0;
    Node *p,*q;
    p = phead -> next;
    q = phead;
    printf("Input name.\n");
    scanf("%s",name);
    printf("Input quantity.\n");
    scanf("%d",&quantity);
    while(p!=NULL)
    {
        if(strcmp(p->name,name)==0)
        {
            search=1;
            if(p -> quantity < quantity)
            {
                break;
            }
            p -> quantity -= quantity;
            if(p -> quantity == 0)
            {
                enough=2;
            }
            if(p -> quantity > 0)
            {
                enough=1;
            }
            break;
        }
        q = p;
        p = p -> next;
    }
    if(search==0)
    {
        printf("Not found %s\n",name);
        return;
    }
    if (enough == 0)
	{
	    printf("Not enough!\n");
		return;
	}
	if (enough == 2)
	{
		q -> next = p -> next;
		free(p);
		n--;
	}
}
void save()
{
    FILE *fp;
	fp = fopen("Data","w");
	fprintf(fp,"%d\n",n);
	Node *p, *q;
	p = phead -> next;
	q = phead;
	free(q);
	while (p != NULL) {
		fprintf(fp,"%s\n",p -> name);
		fprintf(fp,"%d\n",p -> quantity);
		q = p;
		p = p -> next;
		free(q);
	}
}
