#include<stdio>

int main()
{
    int i=0;
    while(++i)
    {
        if((i/12.0+i/6.0+i/7.0+5.0+i/2.0+4.0)==i)
        {
            printf("\n%d",i-4);
            break;
        }
    }
    return 0;
}