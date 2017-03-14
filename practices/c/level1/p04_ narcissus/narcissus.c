#include<stdio.h>

void main()
{
	int one, ten, hun;

	for (int num= 100;num < 1000;num++)
	{
		one = num % 10;
		ten = (num % 100) / 10;
		hun = num / 100;
		if (num == (one*one*one) + (ten*ten*ten) + (hun*hun*hun))
		{
			printf("%5d", num);
		}
	}
}