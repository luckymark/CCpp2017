#include<stdio.h>
#include<time.h>
int main()
{
    int n,k=0;
    scanf("%d",&n)
    int p[n];
    bool o[n];
    double a=clock();
    for(int i=0;i<n;i++)
    {
        o[i]=1;
        p[i]=0;
    }
    for(int i=1;i<n;i++)
    {
        if(o[i]!=0)
        {
            p[k]=i+1;
            printf("%d\n",i+1);
            k++;
        }
        for(int j=0;p[j]!=0 and p[j]*(i+1)<=n;j++)
        {
            o[p[j]*(i+1)-1]=0;
            if((i+1)%p[j]==0) break;
        }
    }
    double b=clock();
    printf("time:%f",b-a);
    return 0;
}
