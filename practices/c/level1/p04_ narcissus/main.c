#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_narcissus(int num)
{
    int tmp = num, result = 0;
    for(int i = 2; i >=0; --i)
    {
        result += pow(tmp % 10, 3);
        tmp /= 10;
    }
    if (num == result)
        return true;
    else
        return false;
}
int main()
{
    for(int i = 100; i < 1000;i ++)
    {
        if(is_narcissus(i))
        {
            printf("%d\n", i);
        }
    }
    return 0;
}