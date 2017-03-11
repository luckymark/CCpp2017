#include <stdio.h>
#include <math.h>

int is_prime(int n){
    if(n<2)
        return 0;
    if(n==2)
        return 1;
    else
        for(int i=2;i<=sqrt(n);i++){
           if(n%i==0){
            return 0;
            break;
           }
    }
    return 1;
}

int main(void){
    int n;
    printf("please input n:\n");
    scanf("%d",&n);
    if(is_prime(n))
        printf("%d is a prime",n);
    else
        printf("%d is not a prime",n);
    return 0;
}
