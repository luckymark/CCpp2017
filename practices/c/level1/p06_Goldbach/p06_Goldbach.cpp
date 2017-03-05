#include<stdio.h>

int isprime(int i);
int main()
{
	int x, y;
	for(x = 4; x < 101; x += 2)
	{
		for(y = 2; y <= x / 2; y++)
		{
			if(isprime(y) != 0)
				if(isprime(x - y) != 0)
					printf("%d = %d + %d\n", x, y, x - y);
		}
	}
	printf("Proof done.\n");
	return 0;
}

int isprime(int i)
{
	int j;
	for(j = 2; j < i; j++)
	{
		if(i % j == 0)
			break;
	}
	if(i == j)
		return 1;
	else
		return 0;
}
