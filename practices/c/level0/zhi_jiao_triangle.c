#include <stdio.h>

int main(void){
    int a,b,c;
    printf("Please input a,b,c of triangle:\n");
    scanf("%d,%d,%d",&a,&b,&c);

    if(a*a == b*b + c*c || b*b == c*c + a*a || c*c == a*a + b*b)
        printf("该三角形为直角三角形\n");
    else
        printf("该三角形不是直角三角形\n");

    return 0;

}
