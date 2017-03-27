#include <stdio.h>
#include <stdlib.h>

void Init_list();
void Build_list();
void Printf_list();
void Overturn_list();
void Search_list(int x);

struct node
{
    int data;
    struct node * next;
}*head_ptr,*pre_ptr;



int main(void)
{
    Init_list();
    Build_list();

    int choice;
    printf("what do you want to do:\n");
    printf("1.print linkedlist \n2.overturn the linkedlist \n3.search a member in the linkenlist \n4.quit\n");
    scanf("%d",&choice);
    fflush(stdin);
    int x;

    switch(choice)
    {
    case 1:
       Printf_list();
       break;
    case 2:
       Overturn_list();
       break;
    case 3:

       printf("input the number you want to search:\n");
       scanf("%d",&x);
       fflush(stdin);
       Search_list(x);
       break;
    case 4:
        break;
    default:
        printf("error\n");
    }

    return 0;
}




void Init_list()
{
    head_ptr=(struct node*)malloc(sizeof(struct node));
    /*if(head_ptr == NULL)
    {
        printf("Fail to request for room!\N");
    }*/
    head_ptr->next=NULL;
    pre_ptr=(struct node*)malloc(sizeof(struct node));
   /*if(pre_ptr == NULL)
    {
        printf("Fail to request for room!\N");
    }*/
    pre_ptr->next=NULL;
}

void Build_list()
{
    printf("The number of the list you want to build:\n");

    int n;
    scanf("%d",&n);
    fflush(stdin);

    printf("Input all members:\n");
    int x;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        fflush(stdin);
        struct node* ptr;
        ptr=(struct node*)malloc(sizeof(struct node));
        ptr->data=x;
        ptr->next=NULL;
        if(head_ptr->next==NULL)
        {
            head_ptr->next=ptr;
            pre_ptr=ptr;
        }
        pre_ptr->next=ptr;
        pre_ptr=ptr;

    }
}


void Printf_list()
{
    struct node* ptr;
    ptr = head_ptr->next;
    while(ptr != NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }

}

void Overturn_list()
{
    struct node *ptr,*next_ptr,*now_ptr;
    ptr=head_ptr->next;
    pre_ptr=ptr;
    now_ptr=NULL;
    while(ptr != NULL)
    {
        next_ptr=ptr->next;
        ptr->next=now_ptr;
        now_ptr=ptr;
        ptr=next_ptr;
    }
    head_ptr->next=now_ptr;
}

void Search_list(int x)
{
    int turn=1,seache_result=0;
    struct node *ptr;
    ptr=head_ptr->next;
    while(ptr!=NULL)
    {
        if(ptr->data == x)
        {
            seache_result=1;
            printf("%d",turn);
        }
        ptr=ptr->next;
        ++turn;
    }
    if(seache_result==0)
    {
        printf("-1");
    }
}




