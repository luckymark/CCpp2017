#include <stdio.h>
#define RATE 6.90698365

int main(void){
    int dollar,RMB;
    printf("Please input dollar:");
    scanf("%d",&dollar);
    RMB = dollar * RATE;
    printf("%d dollar = %d RMB",dollar,RMB);

    return 0;



}
