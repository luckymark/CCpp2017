#include<stdio.h>
#include<time.h>
#include<math.h>
int is_prime(int n);
void printprime(void);
int main(void)
{
	printprime();
	
	return 0;
} 
void printprime(void)
{
	int max,i;
	float delta;
	scanf("%d",&max);
	delta=clock();
	for(i=2;i<=max;i++)
	{
		if(is_prime(i))
		{
			printf("%d\t",i);
		}
	}
	delta=clock()-delta;
	printf("\nºÄÊ±%.2f ms\n",delta);
}
int is_prime(int n)
{
	int i;
	for(i=2;i<=pow(n,0.5);i++)
	{
		if(n%i==0)
		{
			return 0;
		}
	}
	return 1;
}
