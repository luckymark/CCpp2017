#include<stdio.h>

void hanoi(char,char,char,int);

int main()
{
    hanoi('A','B','C',64);
    return 0;
}

void hanoi(char source,char temp,char target,int number)
{
    if(number==1)
    {
        printf("move from %c to %c\n",source,target);
    }
    else
    {
        hanoi(source,target,temp,number-1);
        hanoi(source,temp,target,1);
        hanoi(temp,source,target,number-1);
    }
}