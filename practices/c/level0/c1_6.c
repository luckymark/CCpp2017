c#include <stdio.h>
int main()
{
	int i,n,max_number=0;
	printf("请输入要比较的数的个数");
	scanf("%d", &n);
	int number;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &number);
		if (number > max_number)
		{
			max_number = number;
		}
	}
	printf("这n个数中最大的数是%d", max_number);
}
