#include <stdio.h>
#include <math.h>
int n;
int main()
{
    int i;
    scanf("%d", &n);
    int m = sqrt(n), f = 0;
    for (i = 2; i <= m; i++)
    {
        if (n % i == 0)
        {
            f = 1;
            break;
        }
    }
    if (f)
    {
        printf("No\n");
    }
    else
    {
        printf("Yes\n");
    }
    return 0;
}
