#include <stdio.h>
int main()
{
	int i;
	for (i = 1; i <= 100; i++)
	{
		if ((0 == i % 3) && (0 != i % 5))
		{
			printf("%d\t", i);
		}
	}
}
