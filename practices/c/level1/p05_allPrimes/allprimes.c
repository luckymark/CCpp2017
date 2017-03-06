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
	printf("\nIt takes %.2f ms\n",delta);
}
int is_prime(int n)
{
	int j;
	
	for(j=2;j<=pow(n,0.5);j++)
	{
		if(n%j==0)return 0;
	}
	return 1;
}
