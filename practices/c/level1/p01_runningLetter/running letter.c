#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
int main(void)
{
    printf("please input a character:");
    char ch;
    scanf_s("%c",&ch);
    int a=0;
    for(;a<100;++a)
    {
        system("cls");
        Sleep(100);
        int i=0;
        for(;i<a;++i)
        printf(" ");
        printf("%c",ch);
    }
    for(;!(a<0);a--)
    {
        system("cls");
        Sleep(100);
        int i=0;
        for(;i<a;++i)
        printf(" ");
        printf("%c",ch);
    }
    return 0;
}


