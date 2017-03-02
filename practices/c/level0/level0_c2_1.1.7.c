#include <stdio.h>
const int n=5;
void main()
{
    int i,j,changed;
    int number[n+1];
    for(i=1;i<n+1;i++){
        scanf("%d",&number[i]);
    }
    for(j=1;j<n;j++){
        changed=0;
        for(i=1;i<n-j+1;i++){
            if(number[i]>number[i+1]){
                number[0]=number[i];
                number[i]=number[i+1];
                number[i+1]=number[0];
                changed=1;
            }
        }
        if(changed==0){
            break;
        }
    }
    for(i=1;i<=n;i++){
        printf("%d\t",number[i]);
    }
}
