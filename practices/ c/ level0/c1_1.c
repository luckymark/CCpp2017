#include <stdio.h>
int main()
{
	int a;
	printf("请输入一个数");
	scanf("%d", &a);
	if (a > 0)
	{
		printf("这个数是正数");
	}
	else if (a != 0)
	{
		printf("这个数是负数");
	}
	else printf("这个数既不是正数也不是负数");
	if (0 == a % 2)
	{
		printf("这个数是偶数");
	}
	else printf("这个数是奇数");
}
