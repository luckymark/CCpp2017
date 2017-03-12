#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
int d[1000], tot = 0;
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
				d[++tot] = i;
			}
		int j;
		for (j = 1; j <= tot; j++)
		{
			if (i * d[j] > 1000)
				break;
			bo[i * d[j]] = 1;
			if (i % d[j] == 0)
				break;
		}
	}
	for (i = 1; i <= tot; i++)
		printf("%d\n", d[i]);
	end = clock();
	printf("Used %d ms.\n", end - start);
	return 0;
}
