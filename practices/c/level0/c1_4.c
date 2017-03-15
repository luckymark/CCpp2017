#include <stdio.h>
int main()
{
	int a, b;
	printf("请输入两个数");
	scanf("%d%d", &a, &b);
	if (a < b)
		a = b;
	printf("两个数中较大的数是%d", a);
}
