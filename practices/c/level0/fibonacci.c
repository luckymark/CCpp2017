#include<stdio.h>
#define SIZE 10

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n-1)+fibonacci(n-2);
}

int main(void)
{
    int i,j;
    printf("Input j:");
    scanf("%d",&j);

    for (i=0;i<j;++i){
        printf("%d\t",fibonacci(i));
    }

    return 0;
}

