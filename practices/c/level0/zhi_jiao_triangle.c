#include <stdio.h>

int main(void){
    int a,b,c;
    printf("Please input a,b,c of triangle:\n");
    scanf("%d,%d,%d",&a,&b,&c);

    if(a*a == b*b + c*c || b*b == c*c + a*a || c*c == a*a + b*b)
        printf("��������Ϊֱ��������\n");
    else
        printf("�������β���ֱ��������\n");

    return 0;

}
