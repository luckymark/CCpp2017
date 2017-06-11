#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
int prime[1000], total;
bool bo_prime[1000];
bool bo_get[1000];
int main() {
	memset(bo_prime, 0, sizeof(bo_prime));
	for (int i = 2; i <= 100; i++)
	{
		if (!bo_prime[i])
		{
			prime[++total] = i;
		}
		int j;
		for (j = 1; j <= total; j++)
		{
			if (i * prime[j] > 100)
				break;
			bo_prime[i * prime[j]] = 1;
			if (i % prime[j] == 0)
				break;
		}
	}
	memset(bo_get, 0, sizeof(bo_get));
	for (int i = 1; i <= total; i++)
	{
		for (int j = i; j <= total; j++)
		{
			bo_get[prime[i] + prime[j]] = 1;
		}
	}
	for (int i = 2; i <= 50; i++)
	{
		if (!bo_get[i * 2])
		{
			puts("False");
			return 0;
		}
	}
	puts("True");
	return 0;
}