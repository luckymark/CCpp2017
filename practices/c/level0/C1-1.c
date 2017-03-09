#include<stdio.h>
int main()
{
	int a;
	scanf("%d",&a);
	if(a>0)
	{
		printf("正数\n");
	} 
	else if(a==0)
	{
		printf("是0\n");
	}else 
	{
		printf("负数\n");
	}
	if(a%2==0)
	{
		printf("是偶数\n");
	} else
	{
		printf("不是偶数\n"); 
	}
	return 0;
} 
