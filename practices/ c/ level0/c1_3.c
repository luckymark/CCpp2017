#include <stdio.h>
int main()
{
	int a;
	printf("请输入年数");
	scanf("%d", &a);
	if ((0 == a % 4 && 0 != a % 100) || 0 == a % 400)
		printf("这一年是闰年");
	else
		printf("这一年不是闰年");
}
