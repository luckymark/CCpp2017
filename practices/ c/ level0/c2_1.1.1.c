#include <stdio.h>
int main()
{
	int i;
	for (i = 2; i <= 200; i++)
	{
		if (0 == i % 2)
		{
			printf("%d\t", i);
		}
	}
}
