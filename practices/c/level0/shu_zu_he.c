#include<stdio.h>
#define SIZE 10

int main(void)
{
    int array[SIZE];
    int i,j,sum=0;
    printf("Please input shu_zu_yuan_su:");

    for (i=0;i<10;i++){
        scanf("%d",&j);
        array[i]=j;
    }

    for (i=0;i<10;i++){
        sum = sum + array[i];
    }

    printf("The sum of array[%d] is:%d ",SIZE,sum);

    return 0;
}

