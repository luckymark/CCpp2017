#include <stdio.h>
const int n=10;
int main()
{
    int i,sum=0;
    int number[n];
    for(i=0;i<n;i++){
        scanf("%d",&number[i]);
    }
    for (i=0;i<n;i++){
        sum+=number[i];
    }
    printf("%d",sum);
    return 0;
}
