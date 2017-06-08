#include<stdio.h>

int main()
{
    int a[999];
    for(int i=0;i<999;i++)
    {
        a[i]=i+2;
    }
    for(int i=0;i<999;i++)
    {
        for(int j=i;j<999;j++)
        {
            int n=(i+2)*(j+2);
            if(n<=1000)
            {
                a[n-2]=0;
            }
            else
            {
                break;
            }
        }
    }
    for(int i=0;i<999;i++)
    {
        if(a[i]!=0)
        {
            printf("%4d",a[i]);
        }
    }

    return 0;
}