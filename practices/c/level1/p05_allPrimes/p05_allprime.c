#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdbool.h> 
#define N 1000001

int main()
{
	float start, finish;
	start = clock();
	bool prime[N];
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for(int i = 2; i < N; i++)
	{
		if(prime[i])
		for(int j = i * 2; j < N; j += i)
		{
			prime[j] = false;
		}
	}
	FILE * fp;
	freopen("allprime.txt", "w", stdout);
	for(int k = 0; k <N; k++)
	{
		if(prime[k])
			printf("%d ", k);
	}
	finish = clock();
	printf("\n%g\n", (finish - start) / CLOCKS_PER_SEC);
	return 0;
}
