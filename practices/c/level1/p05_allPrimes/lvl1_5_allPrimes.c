// allPrime.c
//

/* code: 	Step0 for Eula
 * author:	Kyrios0
 * date: 	2017.02.21
 * state: 	finished
 * version: 2.0.2
 */
#define MAX 200000000
#include<stdio.h>
#include<stdlib.h>//malloc()
#include<string.h>
#include<Windows.h>

int judge[MAX];
long prime[MAX];



int main(int argc, char** argv)
{
	long ct = 0;
	judge[0] = judge[1] = 1;
	
	for (long i = 2; i < MAX; i++)
	{
		if (!judge[i])
		{
			prime[ct] = i;
			ct++;
		}
		
		for (int j = 0; j < ct && i * prime[j] <  MAX; j++)
		{
			judge[i * prime[j]] = 1;
			if (!(i%prime[j]))
			{
				break;
			}
				
		}
	}

	FILE *fpt;
	fpt = fopen("PrimeList.txt", "w");

	puts("Start writing... Please wait a moment.");

	for (long i = 0; ; i++)//output
	{
		if (!prime[i])
		{
			break;
		}
		fprintf(fpt, "%d, ", prime[i]);
		if ((i % 100000 == 0) && (i != 0))
		{
			printf("%d numbers has been writen: %d \n", i, prime[i]);
		}
	}

	puts("DONE!");

	system("pause");

	return 0;
}