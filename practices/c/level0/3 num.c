#include <stdio.h>

void main()
{
	int a,b,c;
	printf("������������");
	scanf("%d %d %d",&a,&b,&c);
	if(a>b)
	{
	    if(a>c)
		{
			printf("����Ϊ%d",a);
		}
		else
		{
			printf("����Ϊ%d",c);
		}
	}
	else
	{
		if(b<c)
		{
			printf("����Ϊ%d",c);
		}
		else
		{
			printf("����Ϊ%d",b);
		}
	}
}
