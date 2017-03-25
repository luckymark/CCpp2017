#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
int d[1000], tot;
bool bo[1000];
bool get[1000];
int main() {
	memset(bo, 0, sizeof(bo));
	for (int i = 2; i <= 100; i++)
	{
		if (!bo[i])
		{
			d[++tot] = i;
		}
		int j;
		for (j = 1; j <= tot; j++)
		{
			if (i * d[j] > 100)
			{
				break;
			}
			bo[i * d[j]] = 1;
			if (i % d[j] == 0)
			{
				break;
			}
		}
	}
	memset(get, 0, sizeof(get));
	for (int i = 1; i <= tot; i++)
	{
		for (int j = i; j <= tot; j++)
		{
			get[d[i] + d[j]] = 1;
		}
	}
	for (int i = 2; i <= 50; i++)
	{
		if (!get[i * 2])
		{
			puts("False");
			return 0;
		}
	}
	puts("True");
	return 0;
}
