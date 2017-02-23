#include <cstdio>
int main()
{
    for(int i=10;i<=100;i++)
    {
        int son=i/2;
        if(17*i-252==28*son)
        {
            printf("%d\n",i-4);
            break;
        }
    }
    return 0;
}
