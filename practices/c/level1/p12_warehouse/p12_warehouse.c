#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define max 30

int ifempty = 0;//��־���ж������Ƿ�Ϊ�� 
FILE *fp;

typedef struct list    /* ����˫������ṹ�� */ 
{
    int number;           /* ������ */
    char name[max];      /* �������� */    
    int counter;        /* �������� */
struct list  *prior, *next;
/* ������ָ�룬�ֱ�ָ����ǰ���ͺ�� */
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
    if(!(L = (node *)malloc(sizeof(node)))) //����ռ� 
    {
        printf("\n");
        exit(1);
    }
    create(L); //���ú���������ͷ�ڵ� 
    read(L, fp);
    while(1)
    {
        printf("\n============================\n");
        printf("   1.    �������\n");
        printf("   2.    �������\n");
        printf("   3.    ��ʾ����\n");
        printf("   0.    �˳�\n");
        printf("=============================\n");
        printf("  ѡ��0--3:");
        scanf("%d", &x);
        switch(x)
        {
            case 1: input(L); break; //������⺯��
            case 2: output(L); break; //���ó��⺯�� 
            case 3: display(L); break; //������ʾ�������
            case 0:
            {
                save(L, fp);
                printf("\n��лʹ��!\n");
                exit(0); //�˳����� 
            }
            default:
            {
                printf("\n�����������0--4!\n");  
                getchar();
            }
        }
    }
}

node  *create(node *L) //��������ͷ�ڵ� 
{
    ifempty = 0;
    L->next = NULL; L->prior = NULL;
    L->number = L->counter = 0;
    strcpy(L->name, " ");    
    return L;
}

node *input(node *L)//������⺯�� 
{
    node *in, *head;
    head = in = (node *)malloc(sizeof(node));//����ռ� 
    head = L;
    printf("\n�������������:\n");
    printf("���:");
    scanf("%d", &in->number);
    printf("����:");
    scanf("%s", &in->name);
    printf("����:");
    scanf("%d", &in->counter);
    if(L->next == NULL)   //���ֻ��ͷ�ڵ� 
    {                   //�Ѹղ������in�ڵ� 
        L->next = in;     //����ͷ�ڵ���� 
        L->prior = in;
        in->next = L;
        in->prior = L;
        ifempty++; //ifempty��1
    }
    else
    {//�����ǰL����һ���ڵ㲻��ͷ�ڵ� 
        while((L = L->next) != head)
        {//��������������L->number,��嵽L��ǰ�� 
            if(L->number < in->number)
            {
                in->next = L;
                in->prior = L->prior;        
                L->prior->next = in;
                L->prior = in;
                ifempty++; //ifempty��1
                return(head);
            }            
        }
//����ı�ű�������Ŷ�С����嵽���һ���ڵ㣬����β���� 
        head->prior->next = in;
        in->prior = head->prior;
        head->prior = in;
        in->next = head;
        ifempty++; //ifempty��1
    }         
    return head;
}

node *output(node *L)//����ĺ��� 
{
    int y;
    node *head = L;
    if(ifempty == 0)//����Ƿ��л������� 
    {
        printf("\nû�л�������ϵͳ\n");
        getchar();
        return(head);
    }    
    while(1)
    {
        printf("\n=============\n");
        printf("1.����ų���\n");
        printf("2.�����Ƴ���\n");
        printf("0.������һ��\n");
        printf("==============\n");
        printf("ѡ��0--2:");
        scanf("%d", &y);
        switch(y)
        {
            case 1: outnum(L);break;//���ð���ų���ĺ��� 
            case 2: outname(L);break;//���ð����Ƴ���ĺ��� 
            case 0: return(L);
            default:
            {
                printf("\n�������������0-2��\n");
                getchar();
                printf("\n");
            }
        }
    }
}  
      
node *outnum(node *L)//����ų��� 
{          
    int num;
    node *head = L;
    printf("\n��������������:");
    scanf("%d", &num);
    while((L = L->next) != head)
    {//����ҵ���ɾ���ڵ� 
        if(L->number == num)
        {
            L->prior->next = L->next;
            L->next->prior = L->prior;
            ifempty--; //ifempty��1    
            printf("\n���Ϊ%d�Ļ���ɹ�����\n\n", num);    
            getchar();
            return head;
        }    
    }
    printf("û�д˱�ŵĻ����鿴�Ƿ��л���\n\n");
    getchar();
    return (head);
}
            
node *outname(node *L) //�����Ƴ��⺯�� 
{
    char na[32];
    node *head = L;
    printf("\n�����������������:");
    scanf("%s", &na);
    while((L = L->next) != head)
    {//����ҵ���ɾ���ڵ� 
        if(strcmp(L->name, na) == 0)
        {
            L->prior->next = L->next;
            L->next->prior = L->prior;
            ifempty--;    //ifempty��1            
            printf("\n����Ϊ%s�Ļ���ɹ�����\n\n",na);
            getchar();
            return (head);
        }
    }
    printf("û�д����ƵĻ����鿴�Ƿ��л���\n\n");
    getchar();
    return(head);
}        
void display(node *L)//��ʾ�����嵥 
{
    node *head = L;
    if(ifempty == 0)
    {
        printf("û�л������ʾ\n\n");
        getchar();
        return;
    }
    L = L->next;
    do
    {        
        printf("\n���:%d\n",L->number);
        printf("����:%s\n",L->name) ;
        printf("����:%d\n\n",L->counter);
    }while((L=L->next)!=head);
    getchar();                
}

int read(node *L, FILE *fp)
{
    if((fp = fopen("data.dat", "rb")) == NULL)
    {
        printf("���ļ�ʧ��");
        return NULL; 
    }
    while(!feof(fp))
    {
        node *in, *head;
        head = in = (node *)malloc(sizeof(node)); //����ռ� 
        head = L;
        fscanf(fp, "%d %s %d", &in->number, &in->name, &in->counter);
        if(L->next == NULL)   //���ֻ��ͷ�ڵ� 
        {                   //�Ѹղ������in�ڵ� 
            L->next = in;     //����ͷ�ڵ���� 
            L->prior = in;
            in->next = L;
            in->prior = L;
            ifempty++;  //ifempty��1
        }
        else
        {  //�����ǰL����һ���ڵ㲻��ͷ�ڵ� 
            while((L = L->next) != head)
            {  //��������������L->number,��嵽L��ǰ�� 
                if(L->number < in->number)
                {
                    in->next = L;
                    in->prior = L->prior;        
                    L->prior->next = in;
                    L->prior = in;
                    ifempty++; //ifempty��1
                    return(head);
                }
            }
            //����ı�ű�������Ŷ�С����嵽���һ���ڵ㣬����β���� 
            head->prior->next = in;
            in->prior = head->prior;
            head->prior = in;
            in->next = head;
            ifempty++; //ifempty��1
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
        printf("\nû�����ݿɱ���\n");
        return -1;
    }
    if((fp = fopen("data.dat","wb")) == NULL)
    {
        printf("���ļ�ʧ��!\n");
        return -1;
    }
    do
    {
        fprintf(fp, "%d %s %d ", L->number, L->name, L->counter);
    }while((L=L->next)!=head);
    printf("\n�����ѱ���\n");
    fclose(fp);
    return 0;
}
