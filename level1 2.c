#include <stdio.h>
#include <stdlib.h>
int main()
{
	int num,mark=0,i;
	printf("输入一个大于二的整数");
	scanf("%d", &num);
	for (i=2;i<num;i++)
	{
		if (num % i == 0)
		{
			printf("%d不是素数", num);
			mark = 1;
			break;
		}
	  }

	if (mark == 0)
	{
		printf("%d是素数", num);
	}
		system("pause");
		return 0;
}
