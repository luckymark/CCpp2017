#include<stdio.h>
void mov(int n,char f,char m,char t)
{
    if(n!=1)
    {
        mov(n-1,f,t,m);
        printf("move plate %d from %c to %c\n",n,f,t);
        mov(n-1,m,f,t);
    }
    else printf("move plate %d from %c to %c\n",n,f,t);
}
int main()
{
    int n;
    printf("total plates:");
    scanf("%d",&n);
    mov(n,'A','B','C');
    return 0;
}
