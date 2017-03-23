#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10000

int prime(int a);
int Goldbahe(int b);
int pri[MAX]={0};

int main(void){
    int n;
    printf("please input n(4~%d之间的偶数):",MAX);
    scanf("%d",&n);

    if(n%2 == 0){
       prime(MAX);
       Goldbahe(n);
    }

    else{
        printf("error input");
    }
    return 0;
    }

int prime(int a){
    int i,j;

    if(i=1){
            pri[i]=1;}
    if(i=2){
            pri[i]=0;}
    for(i=3;i<=MAX;i++){
        for(j=2;j<=sqrt(i);j++){
            if(i%j==0){
                pri[i]=1;
            }
        }
    }
}

int Goldbahe(int b){
    int i,j;
    for(i=1;i<=MAX;i++){
            for(j=i;j<=MAX;j++){
                if(pri[i]==0&pri[j]==0&b==i+j){
                    printf("%d = %d + %d\n",b,i,j);
    }
           }

        }
    }

