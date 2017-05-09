#include <stdio.h>
int next[10000];
int pre[10000];
int val[10000];
int n, tot;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d", &a);
        next[tot] = tot + 1;
        tot++;
        val[tot] = a;
    }
    for (int now = 1; now != 0; now = next[now])
    {
        printf("%d ", val[now]);
    }
    puts("");
    for (int now = 1; now != 0; now = next[now])
    {
        pre[next[now]] = now;
    }
    for (int now = tot; now != 0; now = pre[now])
    {
        if (val[now] == 5)
        {
            printf("%d ", now);
        }
    }
    printf("-1\n");
    return 0;
}
