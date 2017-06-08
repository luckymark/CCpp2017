#include<stdio.h>
#include<math.h>

int isPrime(int n)
{
    int n_sqrt=sqrt(n);
    for(int i=2;i<n_sqrt;i++)
    {
        if(n%i==0)
        {
            return 0;   //0 as false.
        }
    }
    return 1;   //1 as true.
}

int count=0;

int main()
{
    for(int i=4;i<=100;i+=2)
    {
        for(int j=2;j<i;j++)
        {
            if(isPrime(i-j)&&isPrime(j))
            {
                count++;
                break;
            }
        }
    }
    if(count!=49)
    {
        printf("False");
    }
    else
    {
        printf("True");
    }
   
    return 0;
}