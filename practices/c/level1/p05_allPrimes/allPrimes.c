#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
int prime[1000], total = 0;
int bo[1000];
clock_t start, end;

int main() {
	start = clock();
	memset(bo, 0, sizeof(bo));
	int i;
	for (i = 2; i <= 1000; i++)
	{
		if (!bo[i])
		{
			prime[++total] = i;
		}
		int j;
		for (j = 1; j <= total; j++)
		{
			if (i * prime[j] > 1000)
				break;
			bo[i * prime[j]] = 1;
			if (i % prime[j] == 0)
				break;
		}
	}
	for (i = 1; i <= total; i++)
	{
		printf("%d\n", prime[i]);
	}
	end = clock();
	printf("Used %d ms.\n", end - start);
	return 0;
}
