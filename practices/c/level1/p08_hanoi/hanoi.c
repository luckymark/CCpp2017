#include <stdio.h>
#include <stdlib.h>

void hanoi(int n,char start,char medium,char end);

int main()
{
    int n;
    
    printf("input n:");
    scanf("%d",&n);
    hanoi(n,'A','B','C');
    
    return 0;
}

void hanoi(int n,char start,char medium,char end){
    if(1 == n){
        printf("%c->%c\n",start,end);
    }

    else{
        hanoi(n-1,start,end,medium);
        printf("%c->%c\n",start,end);
        hanoi(n-1,medium,start,end);
    }
}


