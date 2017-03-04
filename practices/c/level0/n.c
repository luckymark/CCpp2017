#include<stdio.h>
#define M 10000
int main(void)
{
   int i,j=0,n;
   int a[M],b[M];

   printf("please input n:\n");
   scanf("%d",&n);
   printf("please input %d numbers:\n",n);

   for(i=1;i<=n;++i){
        scanf("%d",&a[i]);
   }

   for(i=n;i>=0;i--){
        b[++j]=a[i];
   }

   for(i=1;i<=n;++i){
        printf("%d\t",b[i]);
   }

   return 0;
}


