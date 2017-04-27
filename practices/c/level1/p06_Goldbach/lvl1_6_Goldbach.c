// Goldbach.c
//

/* code: 	Goldbach (change from lvl1_5)
* author:	Kyrios0
* date: 	2017.02.26
* state: 	finished
* version:  2.0.1
*/

#include<stdio.h>
#include<string.h>
#include<Windows.h>
int prime[1000000];
int judge[80000];

int main(int argc, char** argv)
{
	long MAX = 1000000;//about 8min
	long ct = 0;
	judge[0] = judge[1] = 1;

	for (long i = 2; i < MAX; i++)
	{
		if (!judge[i])
		{
			prime[ct] = i;
			ct++;
		}

		for (int j = 0; j < ct && i * prime[j] < MAX; j++)
		{
			judge[i * prime[j]] = 1;
			if (!(i%prime[j]))
			{
				break;
			}

		}

	}

	FILE *fpt;
	fpt = fopen("Goldbach.txt", "w");
	puts("Start writing... Please wait a moment.");

	int x = 0, y = 0;

	for (int i = 4; i <= 1000000;)
	{
		if (prime[x] < i - 300)//The speed can be increased by 40% if i == 100,000
		{
			x++;
		}

		if (i - prime[x] != prime[y])
		{
			x++;
			if (prime[x] > 1000000)
			{
				x = 0;
				y++;
			}
		}
		else
		{
			fprintf(fpt, "%d = %d + %d\n", i, prime[x], prime[y]);
			if (i % 20000 == 0)
			{
				printf("%d lines has been writen.\n", i / 2);
			}
			x = 0; y = 0, i += 2;
			continue;
		}

	}

	puts("DONE!");

	system("pause");

	return 0;
}