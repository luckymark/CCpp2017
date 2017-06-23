// isPrime.c
//


/* code:	Step0 for Eula Prime (change from lvl1_5)
* author:	Kyrios0
* date: 	2017.02.21
* state: 	finished
* version:  2.0.2
*/

#include<stdio.h>
#include<stdlib.h>//malloc()
#include<string.h>
#include<Windows.h>



int main(int argc, char** argv)
{
	long max;
	puts("Prime Number Detection System");
	puts("Please enter the number you want to detect（It should be no less than 2）");
	scanf("%ld", &max);

	long ct = 0;
	int *judge;
	judge = (int*)malloc((max + 1) * sizeof(int));
	long *prime;
	prime = (long*)malloc((max + 1) * sizeof(long));
	memset(prime, 0, (max + 1) * sizeof(prime));
	memset(judge, 0, (max + 1) * sizeof(judge));
	judge[0] = judge[1] = 1;
	for (long i = 2; i < max; i++)
	{
		if (!judge[i])
		{
			prime[ct] = i;
			ct++;
		}

		for (int j = 0; j < ct && i * prime[j] <= max; j++)
		{
			judge[i * prime[j]] = 1;
			if (!(i%prime[j]))
			{
				break;
			}

		}
	}
	
	printf((!judge[max]) ? ("%d is a prime number\n") : ("%d is a composite number\n"), max);

	system("pause");

	return 0;
}
