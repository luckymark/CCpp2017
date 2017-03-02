#include <stdio.h>
void main()
{
    int i,n;
    scanf("%d",&n);
    int number[n];
    for(i=1;i<=n;i++){
        scanf("%d",&number[i]);
    }
    for(i=n;i>=1;i--){
        printf("%d\t",number[i]);
    }
}
