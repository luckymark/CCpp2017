#include <stdio.h>
void main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a*a== b*b+ c*c||b*b== a*a+ c*c||c*c== a*a+ b*b){
        printf("这个三角形是直角三角形");
    }
    else{
        printf("这个三角形不是直角三角形");
    }
        
}
