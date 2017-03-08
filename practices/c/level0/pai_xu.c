#include <stdio.h>
#include <stdlib.h>
int main(void)

{
    int array[10];
    int i,j,k;

    for(i=0;i<=9;++i){
        array[i]=0;
    }

    for(i=1;i<=5;++i){
        scanf("%d",&k);
        array[k]++;
    }

    for(i=0;i<=9;++i){
        for(j=1;j<=array[i];++j)
            printf("%d\t",i);

    }

    system("pause");

    return 0;
}
