#include <stdio.h>

int main()
{
	int a,b;
	printf("请输入a的值： ");
	scanf("%d",&a);
	b=a%13;
	
	if(b==0)
	{
		printf("a为13的倍数\n");
	}
	else
	{
		printf("a不为13的倍数");
	}
	
	return 0;
}
