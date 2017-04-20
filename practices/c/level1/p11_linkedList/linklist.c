#include<stdio.h>
#include<stdlib.h>
struct list
{
    int i;
    struct list* next;
}
int find5(struct list* list1,int z);
void reverse(struct list* list1);
int main()
{
    int i=0,z=0;
    int quantity=0,number;
    struct list* list1,*listlink;
    list1=(struct list*)malloc(sizeof(struct list));
    listlink=list1;
    printf("How much nunmber do you want enyte?");
    scanf("%d",&quantity);
    while(i<quantity)
    {
        if(scanf("%d",&number)!=1)
        {
            printf("Please enter a integer number");
            continue;
        }
        else
        {
            if(i!=quantity-1)
            {
                listlink->i=number;
                listlink->next=(struct list*)malloc(sizeof(struct list));
                listlink=listlink->next;
            }
            else
            {
                listlink->i=number;
                listlink->next=NULL;
            }
        }
        i++;
    }
    reverse(list1);
    z=find5(list1,z);
    if(z!=-1)
    {
        list1=list->next;
        z=find5(list1,z);
    }
    return 0;
}
void reverse(struct list* list1)
{
    struct list* link1,*link2;
    while(list1->next!=NULL)
    {
        link1=list1;
        link2->next=link1;
        link2=list1->next;
        list1=list1->next;
    }
}
int find5(struct list* list1,int z)
{
    while(list1!=NULL)
    {
        list1->i==5?return z: ;
        z++;
        list1=list->next;
    }
    if(list1==NULL)return -1;
}