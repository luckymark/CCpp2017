#include<stdio.h>

int main()
{
    for(int i=100;i<1000;i++)
    {
        int a=i/100;
        int b=(i-a*100)/10;
        int c=i%10;
        if(a*a*a+b*b*b+c*c*c==i)
        {
            printf("%4d",i);
        }
    }
    return 0;
}