#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define max 30

int ifempty = 0;//标志，判断链表是否为空 
FILE *fp;

typedef struct list    /* 定义双向链表结构体 */ 
{
    int number;           /* 货物编号 */
    char name[max];      /* 货物名称 */    
    int counter;        /* 货物数量 */
struct list  *prior, *next;
/* 定义两指针，分别指向其前驱和后继 */
}node;

node *create(node *L);
node *input(node *L);
node *output(node *L);
node *outnum(node *L);
node *outname(node *L);
int read(node *L, FILE *fp);
int save(node *L, FILE *fp);
void display(node *L);

void main()
{
    int x;
    node *L;
    if(!(L = (node *)malloc(sizeof(node)))) //分配空间 
    {
        printf("\n");
        exit(1);
    }
    create(L); //调用函数，创建头节点 
    read(L, fp);
    while(1)
    {
        printf("\n============================\n");
        printf("   1.    货物入库\n");
        printf("   2.    货物出库\n");
        printf("   3.    显示货物\n");
        printf("   0.    退出\n");
        printf("=============================\n");
        printf("  选择0--3:");
        scanf("%d", &x);
        switch(x)
        {
            case 1: input(L); break; //调用入库函数
            case 2: output(L); break; //调用出库函数 
            case 3: display(L); break; //调用显示输出函数
            case 0:
            {
                save(L, fp);
                printf("\n感谢使用!\n");
                exit(0); //退出函数 
            }
            default:
            {
                printf("\n输入错误输入0--4!\n");  
                getchar();
            }
        }
    }
}

node  *create(node *L) //创建链表头节点 
{
    ifempty = 0;
    L->next = NULL; L->prior = NULL;
    L->number = L->counter = 0;
    strcpy(L->name, " ");    
    return L;
}

node *input(node *L)//定义入库函数 
{
    node *in, *head;
    head = in = (node *)malloc(sizeof(node));//分配空间 
    head = L;
    printf("\n请输入货物数据:\n");
    printf("编号:");
    scanf("%d", &in->number);
    printf("名称:");
    scanf("%s", &in->name);
    printf("数量:");
    scanf("%d", &in->counter);
    if(L->next == NULL)   //如果只有头节点 
    {                   //把刚才输入的in节点 
        L->next = in;     //跟在头节点后面 
        L->prior = in;
        in->next = L;
        in->prior = L;
        ifempty++; //ifempty加1
    }
    else
    {//如果当前L的下一个节点不是头节点 
        while((L = L->next) != head)
        {//如果输入的数大于L->number,则插到L的前面 
            if(L->number < in->number)
            {
                in->next = L;
                in->prior = L->prior;        
                L->prior->next = in;
                L->prior = in;
                ifempty++; //ifempty加1
                return(head);
            }            
        }
//输入的编号比其他编号都小，则插到最后一个节点，并首尾相连 
        head->prior->next = in;
        in->prior = head->prior;
        head->prior = in;
        in->next = head;
        ifempty++; //ifempty加1
    }         
    return head;
}

node *output(node *L)//出库的函数 
{
    int y;
    node *head = L;
    if(ifempty == 0)//检测是否有货物输入 
    {
        printf("\n没有货物输入系统\n");
        getchar();
        return(head);
    }    
    while(1)
    {
        printf("\n=============\n");
        printf("1.按编号出库\n");
        printf("2.按名称出库\n");
        printf("0.返回上一层\n");
        printf("==============\n");
        printf("选择0--2:");
        scanf("%d", &y);
        switch(y)
        {
            case 1: outnum(L);break;//调用按编号出库的函数 
            case 2: outname(L);break;//调用按名称出库的函数 
            case 0: return(L);
            default:
            {
                printf("\n输入错误，请输入0-2！\n");
                getchar();
                printf("\n");
            }
        }
    }
}  
      
node *outnum(node *L)//按编号出库 
{          
    int num;
    node *head = L;
    printf("\n请输入出库货物编号:");
    scanf("%d", &num);
    while((L = L->next) != head)
    {//如果找到就删除节点 
        if(L->number == num)
        {
            L->prior->next = L->next;
            L->next->prior = L->prior;
            ifempty--; //ifempty减1    
            printf("\n编号为%d的货物成功出库\n\n", num);    
            getchar();
            return head;
        }    
    }
    printf("没有此编号的货物，请查看是否还有货物\n\n");
    getchar();
    return (head);
}
            
node *outname(node *L) //按名称出库函数 
{
    char na[32];
    node *head = L;
    printf("\n请输入出库货物的名称:");
    scanf("%s", &na);
    while((L = L->next) != head)
    {//如果找到就删除节点 
        if(strcmp(L->name, na) == 0)
        {
            L->prior->next = L->next;
            L->next->prior = L->prior;
            ifempty--;    //ifempty减1            
            printf("\n名称为%s的货物成功出库\n\n",na);
            getchar();
            return (head);
        }
    }
    printf("没有此名称的货物，请查看是否还有货物\n\n");
    getchar();
    return(head);
}        
void display(node *L)//显示货物清单 
{
    node *head = L;
    if(ifempty == 0)
    {
        printf("没有货物可显示\n\n");
        getchar();
        return;
    }
    L = L->next;
    do
    {        
        printf("\n编号:%d\n",L->number);
        printf("名称:%s\n",L->name) ;
        printf("数量:%d\n\n",L->counter);
    }while((L=L->next)!=head);
    getchar();                
}

int read(node *L, FILE *fp)
{
    if((fp = fopen("data.dat", "rb")) == NULL)
    {
        printf("打开文件失败");
        return NULL; 
    }
    while(!feof(fp))
    {
        node *in, *head;
        head = in = (node *)malloc(sizeof(node)); //分配空间 
        head = L;
        fscanf(fp, "%d %s %d", &in->number, &in->name, &in->counter);
        if(L->next == NULL)   //如果只有头节点 
        {                   //把刚才输入的in节点 
            L->next = in;     //跟在头节点后面 
            L->prior = in;
            in->next = L;
            in->prior = L;
            ifempty++;  //ifempty加1
        }
        else
        {  //如果当前L的下一个节点不是头节点 
            while((L = L->next) != head)
            {  //如果输入的数大于L->number,则插到L的前面 
                if(L->number < in->number)
                {
                    in->next = L;
                    in->prior = L->prior;        
                    L->prior->next = in;
                    L->prior = in;
                    ifempty++; //ifempty加1
                    return(head);
                }
            }
            //输入的编号比其他编号都小，则插到最后一个节点，并首尾相连 
            head->prior->next = in;
            in->prior = head->prior;
            head->prior = in;
            in->next = head;
            ifempty++; //ifempty加1
        }
    }
    fclose(fp);
    return 0;
}

int save(node *L, FILE *fp)
{
    node *head = L;
    L = L->next;
    if(ifempty == 0)
    {
        printf("\n没有数据可保存\n");
        return -1;
    }
    if((fp = fopen("data.dat","wb")) == NULL)
    {
        printf("打开文件失败!\n");
        return -1;
    }
    do
    {
        fprintf(fp, "%d %s %d ", L->number, L->name, L->counter);
    }while((L=L->next)!=head);
    printf("\n数据已保存\n");
    fclose(fp);
    return 0;
}
