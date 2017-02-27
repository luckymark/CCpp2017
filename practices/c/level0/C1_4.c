#include <stdio.h>

int main()
{
	int a,b,bgr;
	
	printf("请输入两个整数(逗号隔开)： ");
	scanf("%d,%d",&a,&b);
	bgr=a>=b?a:b;
	printf("%d",bgr);
	
	return 0;
}
