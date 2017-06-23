#include<stdio.h>

void main()
{
	int a,b,k;
	const n=5;
	int i[n];
	printf("ÊäÈë5¸öÊı£º\n");
	for(a=1;a<=n;a++)
	{
		printf("i[%d]=",a);
	scanf("%d",&i[a]);
	}
	for(a=1;a<n;a++)
	for(b=1;b<=n-a;b++)
	if(i[b]>i[b+1])
	{
		k=i[b];
		i[b]=i[b+1];
		i[b+1]=k;
	}
	for(a=1;a<=n;a++)
	printf("%d\n",i[a]);
 } 
