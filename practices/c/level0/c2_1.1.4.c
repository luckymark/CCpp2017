#include <stdio.h>
void printf_X(int a);
void main()
{
	int i, j;
	for (i = 1; i <= 9; i++)
	{
		printf_X(i);
		printf("\n");
	}
}


//自定义的printf_X函数
void printf_X(int a)
{
	int j;
	for (j = 1; j <= a; j++)
	{
		printf("%dX%d=%d\t", a, j, a*j);
	}
}
