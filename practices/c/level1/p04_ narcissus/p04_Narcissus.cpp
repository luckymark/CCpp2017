#include<stdio.h>
#include<math.h>

int main(void)
{
	int i;
	for (i=100; i < 1000; i++)
	{
		if (pow (i / 100, 3) + pow((i % 100) / 10, 3) + pow(i % 10, 3) == i)
		{
			printf("%d\n", i);
		}
	}
	return 0;
}
