#include<stdio.h>
#include<stdlib.h>
int menu();
struct good
{
    char type[20];
    int number;
    struct good* before;
    struct good* next;
}
int main()
{
    int z;
    struct good temp;
    struct good* goods=(struct good*)malloc(sizeof(struct good));
    goods->before=NULL;
    int tynum;
    File* fp;
    fp=fopen("goods.txt","r");
    fcanf(fp,"%d\r\n",&tynum);
    z=menu();
    
    for(int i=0;i<tynum;i++)
    {
        fscanf("%s %d\r\n",&temp->type,&temp->number)
        if(i!=tynum-1)goods->next=(struct good*)malloc(sizeof(struct good));
        else goods->next=NULL;
        goods->type=temp.type;
        goods->number=temp.number;
        goods->next->before=goods;
        if(i!=tynum-1)goods=goods->next;
    }

}
