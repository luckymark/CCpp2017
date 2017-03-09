#include <stdio.h>

    int fac(int i){
    if (1 == i)
        return 1;
    else
        return i*fac(i-1);
    }

int main(void){

    int i,j;
    printf("Please input j:");
    scanf("%d",&j);

    for (i=1;i<=j;++i){
        fac(j);
    }

    printf("%d! = %d",j,fac(j));




    return 0;
}
