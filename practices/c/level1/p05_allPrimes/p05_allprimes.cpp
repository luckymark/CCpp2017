#include<stdio.h>
#include<string.h>
#include<time.h>
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
	//fp = fopen("allprime.txt", "w");
	freopen("allprime.txt", "w", stdout);
	for(int k = 0; k <N; k++)
	{
		if(prime[k])
			printf("%d ", k);
		//fprintf(fp, "%d ", k);
	}
	finish = clock();
	printf("\n%g\n", (finish - start) / CLOCKS_PER_SEC);
	//fclose(fp);
	return 0;
}
