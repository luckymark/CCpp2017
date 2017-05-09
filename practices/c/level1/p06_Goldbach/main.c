#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

const int num = 100;
bool* produce_prime(int max_num) //生成小于等于max_num的素数并返回指针
{
    if(max_num <= 1)
        return NULL;
    bool *ret = (bool*)malloc(sizeof(bool) * (max_num + 1));
    for(int i = 0; i <= max_num; ++i)
        ret[i] = true;
    for(int i = 2; i <= max_num; ++i)
    {
        if(ret[i])
        {
            for(int j = i * i; j <= max_num; j += i)
                ret[j] = false;
        }
    }
    ret[0] = false;
    ret[1] = false;
    return ret;
}

int main()
{
    bool *data = produce_prime(num), result = true;
    int prime[num+1], count = 0;
    for(int i = 0; i <= num; i++)
    {
        if(data[i])
            prime[count++] = i;
    }
    for(int i = 4;result && i <= num; i += 2)
    {
        for(int j = 0; j < count; ++j)
        {
            if(data[i - prime[j]])
            {
                printf("%d = %d + %d\n", i, prime[j], i - prime[j]);
                break;
            }
            else if(j == count - 1)
            {
                printf("%dcan't be solve\n", i);
                result = false;
            }
        }
    }
    if(result)
        puts("Goldbach Conjecture in 100 is right");
    else
        puts("Goldbach Conjecture in 100 is wrong");
    return 0;
}