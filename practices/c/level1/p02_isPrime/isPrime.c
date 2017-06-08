#include<stdio.h>
#include<math.h>

int main()
{
    int n,n_sqrt;
    scanf("%d",&n);
    n_sqrt=sqrt(n);
    for(int i=2;i<n_sqrt;i++)
    {
        if(n%i==0)
        {
            printf("No");
            return 0; 
        }
    }
    printf("Yes");
    return 0;
}