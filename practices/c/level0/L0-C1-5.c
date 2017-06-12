#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if(a>=b)
	{
		if(a>=c)
		{
			printf("a是最大的");
		}else
		{
			printf("c是最大的");
		}
		
	}else
	{
		if(b>=c)
		{
			printf("b是最大的");
		}else
		{
			printf("c是最大的");
		}
	}
	return 0;
} 
