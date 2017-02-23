#include <cstdio>
#include <cmath>
int n;
int main()
{
    scanf("%d",&n);
    int m=sqrt(n),f=0;
    for(int i=2;i<=m;i++)
    {
        if(n%i==0)
        {
            f=1;break;
        }
    }
    if(f)printf("No\n");
    else printf("Yes\n");
    return 0;
}
