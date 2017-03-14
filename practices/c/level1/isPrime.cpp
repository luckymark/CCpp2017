#include<stdil.h>
#include<math.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=2;i<(int)sqrt(n);i++)
    {
        if(n%i==0)
        {
            break;
        }
    }
    if(i==(int)sqrt(n))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}
