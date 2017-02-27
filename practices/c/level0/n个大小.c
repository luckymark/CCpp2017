#include<stdio.h>
main()
{
	int n; 
	printf("nµÄÖµÎª:");
    scanf("%d",&n);
	int i,j,k;
	int a[n]={0};
	for(i=1;i<=n;i++)
	{
		printf("a[%d]:",i);
	    scanf("%d",&a[i]);
	}
	for(i=1;i<=n-1;i++)
	for(j=1;j<n-i;j++)
	if(a[j]<a[j+1])
	{
		k=a[j];
		a[j]=a[j+1];
		a[j+1]=k;
	}
	for(i=1;i<=n;i++)
	printf("%d\t",a[i]);
	printf("\n");
 } 
