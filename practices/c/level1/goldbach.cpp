#include<iostream>
int main()
{
    int n,k=0;
    scanf("%d",&n);
    int p[n];
    bool o[n];
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
            k++;
        }
        for(int j=0;p[j]!=0 and p[j]*(i+1)<=n;j++)
        {
            o[p[j]*(i+1)-1]=0;
            if((i+1)%p[j]==0) break;
        }
    }
    for(int i=4;i<=n;i+=2)
    {
        for(int j=0;p[j]<=i/2;j++)
        {
            for(int k=j;p[j]+p[k]<=i and k<=n;k++)
            {
                if(p[j]+p[k]==i)
                {
                    printf("%d=%d+%d\n",i,p[i],p[j]);
                }
            }
        }
    }
    return 0;
}

