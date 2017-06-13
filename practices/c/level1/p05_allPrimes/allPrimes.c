#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define MN 1000
int prime[1000000], vis[1000000], cnt = 0, i, j;
int main()
{
    memset(vis, 0, sizeof(vis));
    vis[1] = 0;
    clock_t start = clock();
    for (i = 2; i <= MN; i++)
    {
        if (!vis[i])
        {
            prime[cnt++] = i;
        }
        for (j = 0; j < cnt; j++)
        {
            if (i * prime[j] > MN)
                break;
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
    clock_t ends = clock();
    for (i = 0; i < cnt; i++)
    {
        printf("%d ", prime[i]);
    }
    printf("\nTime is : %f", (double)(ends - start) / CLOCKS_PER_SEC);
    return 0;
}
