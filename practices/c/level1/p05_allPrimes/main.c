#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

const int max_num = 10000;

int main()
{
    clock_t start, end;
    start = clock();
    bool *flag = (bool*)malloc(sizeof(bool) * (max_num + 1));
    printf("%p\n", flag);
    for (int i = 0;i <= max_num; ++i)
        flag[i] = true;
    for (int i = 2;i <= max_num; ++i)
    {
        if (flag[i])
        {
            for (int j = i * i; j <= max_num; j += i)
                flag[j] = false;
            printf("%d ", i);
        }
    }
    end = clock();
    printf("\n使用了%dms\n", end - start);
    return 0;
}