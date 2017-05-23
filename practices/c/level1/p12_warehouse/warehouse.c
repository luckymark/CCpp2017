#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#ifdef _WIN32
#define clear(); system("cls");
#endif
#ifdef linux
#define clear(); system("clear");
#endif

struct item
{
    char type[255];
    int amount;
}list[1024]={0};
int length=0;

void listout();
void putout();
void putin();
void writeout();

int main()
{
    FILE* fp;
    int i=0;

    //-----read
    fp=fopen("DATA.txt","r");
    char buffer[255];
    while(1)
    {
        fgets(buffer, 255, fp);//char *fgets(char *buf, int bufsize, FILE *stream);
        if(*buffer=='0')
        {
            break;
        }
        char* b_type;
        char* b_amount;
        b_type=strtok(buffer,"#");
        b_amount=strtok(NULL,"");
        strcpy(list[i].type,b_type);
        list[i].amount=atoi(b_amount);
        i++;
        length=i;
    }
    //-------------------------------------

    //-----menu
    while(1)
    {
        clear();
        int n;
        printf("1.list\n2.Input\n3.Output\n4.Exit\n-->");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                listout();
                getchar();
                getchar();
                break;
            case 2:
                putin();
                getchar();
                getchar();
                break;
            case 3:
                putout();
                getchar();
                getchar();
                break;
            case 4:
                writeout();
                return 0;
                break;
            default:
                printf("No such option to choose.\n");
                getchar();
                getchar();
        }
    }
    


    
    return 0;
}

void listout()
{
    int j;
    for(j=0;j<length;j++)
    {
        printf("Item:%s\tAmount:%d\n",list[j].type,list[j].amount);
    }
}

void putout()
{
    char type[255];
    int amount,j;
    printf("Item type:");
    scanf("%s",type);
    for(j=0;j<length;j++)
    {
        if(!strcmp(type,list[j].type))
        {
            printf("amount to put out:");
            scanf("%d",&amount);
            if(amount<0)
            {
                printf("Wrong number.\n");
            }
            else if(amount>list[j].amount)
            {
                printf("No enough items");
            }
            else
            {
                list[j].amount-=amount;
                printf("Output complete.\n");
            }
            return;
        }
    }
    printf("No such item.\n");
}

void putin()
{
    char type[255];
    int amount,j;
    printf("Item type:");
    scanf("%s",type);
    for(j=0;j<length;j++)
    {
        if(!strcmp(type,list[j].type))
        {
            printf("amount to put in:");
            scanf("%d",&amount);
            if(amount<0)
            {
                printf("Wrong number.\n");
            }
            else
            {
                list[j].amount+=amount;
                printf("Input complete.\n");
            }
            return;
        }
    }
    struct item newitem;
    printf("New item type!\namount to put in:");
    scanf("%d",&amount);
    strcpy(newitem.type,type);
    newitem.amount=amount;
    list[length]=newitem;
    ++length;
    printf("Input complete.\n");
}
void writeout()
{
    FILE* fp;
    fp=fopen("DATA.txt","w");
    char buffer[255],buf2[255];
    int j;
    for(j=0;j<length;j++)
    {
        strcpy(buffer,list[j].type);
        strcat(buffer,"#");
        sprintf(buf2,"%d",list[j].amount);
        strcat(buffer,buf2);
        strcat(buffer,"\n");
        fputs(buffer,fp);
    }
}
/*
dd1009#7
dd1010#9
dd1011#45
0
*/
