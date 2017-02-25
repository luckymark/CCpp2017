#include<stdio.h>
#include<stdlib.h>
#include <math.h>
//if is PrimeNumber then print it,or there is nothing output.
int is_PrimeNumber(int n)
{
		if(n<2) return 0;
		if(n==2) return 1;
		for(int i=2;i<sqrt(n+1);i++)
		{
			
			if(n%i == 0) 
			{
				return 0;
			}
			if(i>2)
			{
				if(i%2) continue;
			}
			 
		}
		return 1;	

}

int main()
{
	int n;
	if(scanf("%d",&n) == 1)
	{
		if(is_PrimeNumber(n)) 
		{
			printf("%d",n);
		}
	}

	 
	return 0;
}
