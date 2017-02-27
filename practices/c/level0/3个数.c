#include <stdio.h>
void main()
{
	int a,b,c;
	printf("输入三个数：");
	scanf("%d %d %d",&a,&b,&c);
	if(a>b)
	{
		if(a>c)
		printf("最大的为%d",a);
		else
		printf("最大的为%d",c);
	}
	else
	{
		if(b<c)
		printf("最大的为%d",c);
		else
		printf("最大的为%d",b);
	}
}
