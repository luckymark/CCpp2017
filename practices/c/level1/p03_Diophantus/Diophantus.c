#include<stdio.h>
int main()
{
	int i, j, k, l;
	for (i = 100;i < 1000;i++)
	{
		k = i % 10;
		j = (i % 100) / 10;
		l = i / 100;
		if (i == (k*k*k) + (j*j*j) + (l*l*l))
		{
			printf("%5d", i);
		}
	}
	return 0;
}