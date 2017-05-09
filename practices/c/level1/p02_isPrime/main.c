#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_prime(int num)
{
    if(num < 2)
        return false;
    int tmp = sqrt(num);
    for(int i = 2;i <= tmp; ++i)
    {
        if(num % i == 0)
            return false;
    }return true;
}
int main()
{
    int num;
    scanf("%d", &num);
    if(is_prime(num))
    {
        puts("这是个质数");
    }
    else
    {
        puts("这不是质数");
    }
    return 0;
}