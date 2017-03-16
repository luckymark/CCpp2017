#include <stdio.h>
#include <string.h>
#include <math.h>
int prime[10000], vis[10000], cnt = 0, i, j, z;
void Shaker()
{
    memset(vis, 0, sizeof(vis));
    vis[1] = 0;
    for (i = 2; i <= 1000; i++)
    {
        if (!vis[i])
        {
            prime[cnt++] = i;
        }
        for (j = 0; j < cnt; j++)
        {
            if (i * prime[j] > 1000)
                break;
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
    for (i = 0; i < cnt; i++)
    {
        printf("%d ", prime[i]);
    }
}
int Judge(int x)
{
    int m = sqrt(x);
    for (z = 2; z <= m; z++)
    {
        if (x % z == 0)
            return 0;
    }
    return 1;
}
int main()
{
    Shaker();
    int k = 0;
    for (i = 4; i <= 100; i += 2)
    {
        for (j = 0; j < cnt && prime[j] < i; j++)
        {
            if (Judge(i - prime[j]))
            {
                k++;
                break;
            }
        }
    }
    int f = 0;
    for (i = 4; i <= 100; i += 2)
    {
        f++;
    }
    printf("%d\n", k == f);
    return 0;
}
