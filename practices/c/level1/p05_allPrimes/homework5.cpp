//好吧，没学过算法，不知道怎么优化，有一点想法，不知道怎么实现。 

#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#define LOW_BOUND 1
#define UP_BOUND 999
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
	for(int i=LOW_BOUND;i<=UP_BOUND;i++)
	{
		if(is_PrimeNumber(i))
		{
			printf("%d\n",i);
		} 
	}
	 	 
	return 0;
} 