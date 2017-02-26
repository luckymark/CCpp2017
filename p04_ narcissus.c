#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a, b, c;
	for (a = 0; a <= 9; a++)
	{
		for (b = 0; b <= 9; b++)
		{
			for (c = 0; c <= 9; c++)
			{
				if (a*a*a + b*b*b + c*c*c == a + 10 * b + 100 * c && !( b == 0 && c == 0))		//排除非三位数（0开头）的情况
				printf("%d%d%d\n", c, b, a);
			}
		}
	}
	system("pause");
	return 0;
}