#include<stdio.h>
int main()
{
	int m,n,a,i;
	m=1;
	
	printf("n的值为:");
	scanf("%d",&n);
	printf("输入n个数");
	
	for(i=1;i<=n;i++)
	{
	scanf("%d",&a);
	printf("\n");
	if(a>m)
	{
		m=a;
		
	}
	}
	printf("最大的数为%d",m);
 } 	
