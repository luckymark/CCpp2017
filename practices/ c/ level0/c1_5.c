#include <stdio.h>
int main()
{
	int a, b, c;
	printf("请输入三个数");
	scanf("%d%d%d", &a, &b, &c);
	if (a > b)
	{
		if (c > a)
			a = c;
	}
	else
	{
		if (b > c)
			a = b;
		else
			a = c;
	}
	printf("这三个数中最大的是%d", a);
}
