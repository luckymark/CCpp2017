#include<stdio.h>
int main()

{
	long int i, j;
	printf("Please input a number: \t");
	scanf_s("%d", &i);
	if (i == 2) {
		printf("%d  is a Prime.", i);
	}
	else if (i == 1) {
		printf("%d  is not a Prime.", i);
	}
	else
	{
		j = 2;
		while (i > j)
		{
			if (i%j == 0)
				break;

			else
			{
				if (i == j + 1)
				{
					printf("%d  is a Prime.", i);
					break;
				}
				j++;

			}
		}
    if (i > j + 1)
		printf("%d  is not a Prime.", i);
	}
}