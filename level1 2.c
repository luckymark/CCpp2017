#include <stdio.h>
#include <stdlib.h>
int main()
{
	int num, mark = 0, i;
	printf("input a integer bigger than 2");
	scanf("%d", &num);
	for (i = 2; i<num; i++)
	{
		if (num % i == 0)
		{
			printf("%d isn't a prime number", num);
			mark = 1;
			break;
		}
	}

	if (mark == 0)
	{
		printf("%d is a prime number", num);
	}
	system("pause");
	return 0;
}
