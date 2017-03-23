#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int a=1000,i,j,n;
    int pri[1000]={0};

    if(i=1){
        pri[i]=1;}
    if(i=2){
        pri[i]=0;}
    for(i=3;i<=a;i++){
        for(j=2;j<=sqrt(i);j++){
            if(i%j==0)
        {
                pri[i]=1;
                break;

        }
      }
    }


    printf("please input n(4~1000之间的偶数):");
    scanf("%d",&n);

    for(int i=1;i<=n/2;i++){
        for(int j=n/2;j<=n;j++){
            if(pri[i]==0 & pri[j]==0 & n==i+j){
                printf("%d=%d+%d\n",n,i,j);
            }
        }
    }


    return 0;
}



