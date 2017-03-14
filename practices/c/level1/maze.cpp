#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int i,j;
char a[21][43];
void map()
{
    for(i=0;i<21;i++)
    {
        for(j=0;j<43;j++)
        {
            if(j==0 or j==42)
            {
                a[i][j]='*';
            }
            else if((i==0 or i==20)and j%2==0)
            {
                a[i][j]='*';
            }
            else
            {
                a[i][j]=' ';
            }
        }
    }
    for(i=5;i<13;i++)
    {
        a[i][6]='*';
        a[i][18]='*';
        
        a[i][36]='*';
    }
    for(i=3;i<15;i++)
    {
        a[i][12]='*';
    }
    for(i=2;i<19;i++)
    {
        a[i][27]='*';
    }
    for(j=18;j<38;j++)
    {
        if(j%2==0)
        {
            a[5][j]='*';
        }
    }
    a[15][11]='*';
    a[16][10]='*';
    a[17][9]='*';
    a[11][34]='*';
    a[5][27]=' ';
    a[19][40]='o';
    a[1][2]='x';
}
void prt()
{
    for(int m=0;m<21;m++)
    {
        for(int n=0;n<43;n++)
        {
            printf("%d",a[m][n]);
        }
        printf("\n");
    }
    printf("Move the spot \"x\" to the place \"o\" with \"wasd\"");
}
void mov()
{
    i=1;j=2;
    while(true)
    {
        if(i==19 and j==40)
        {
            a[i][j]='!';
            system("cls");
            prt();
            printf("Yes!!!");
            break;
        }
        else
        {
            char b;
            b=getch();
            if(b==119)
            {
                if(a[i-1][j]=='*')
                {
                    continue;
                }
                a[i][j]=' ';
                i--;
                a[i][j]='o';
                system("cls");
                prt();
            }
            else if(b==115)
            {
                if(a[i+1][j]=='*')
                {
                    continue;
                }
                a[i][j]=' ';
                i++;
                a[i][j]='o';
                system("cls");
                prt();
            }
            else if(b==97)
            {
                if(a[i][j-2]=='*')
                {
                    continue;
                }
                a[i][j]=' ';
                j-=2;
                a[i][j]='o';
                system("cls");
                prt();
            }
            else if(b==100)
            {
                if(a[i][j+2]=='*')
                {
                    continue;
                }
                a[i][j]=' ';
                j+=2;
                a[i][j]='o';
                system("cls");
                prt();
            }
            
        }
    }
}
int main()
{
    map();
    prt();
    mov();
    return 0;
}
