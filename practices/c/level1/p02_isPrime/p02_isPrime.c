#include<stdio.h>

int main(void)
{
    int i, n;
    scanf("%d", &n);
    for(i = 2; i < n; i++)
    {
        if(n % i == 0)
        {
            break;
        }
    }
    if(i == n)
        printf("%d is a prime\n", n);
    else
        printf("%d isn't a prime\n", n);
    return 0; 
} 
