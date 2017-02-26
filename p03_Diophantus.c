#include<stdio.h>
#include<stdlib.h>

void main()
{
	int i;
	for (i = 1; 28 * i != 21 * i + 4 * i + 252; i++)
	{
		;
	}
	printf("丢番图的年纪是%d\n", i);
	system("pause");
}

