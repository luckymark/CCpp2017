#include <stdio.h>
const int n=15;
void main()
{
    int i;
    int x[n];
    x[0]=1,x[1]=1;
    printf("%d\t%d\t",x[0],x[1]);
    for(i=2;i<n;i++){
        x[i]=x[i-1]+x[i-2];
    }
    for(i=2;i<n;i++){
        printf("%d\t",x[i]);
    }
}
