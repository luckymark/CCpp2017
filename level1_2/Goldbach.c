#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int x)
{
	int i;
	int dlm = sqrt((double)x);

	for (i=2; i<=dlm; i++)
	{	if (x%i==0) break; }
	if (x==1) return 0;
	else if (x==2 || x==3 || i>dlm)
	{	return 1; }
	else return 0;
	return 0;
}

int main()
{
	int i,j;

	for (i=4; i<=100; i=i+2)
	{	for (j=2; j<=i/2; j++)
		{	if (isPrime(j) && isPrime(i-j))
			{	printf("\n%d = prime%d + prime%d.",i,j,i-j);
				break; }	}	}
	return 0;
}	
	
