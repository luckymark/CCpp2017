#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#define LOW_BOUND 99
#define UP_BOUND 999
int is_NarcissisticNumber(int n)
{
	if( n == (pow(n/100,3) + pow(n%100/10,3) + pow(n%10,3) ) ) 
	{
		return 1;
	}
	else 
	{
		return 0;
	}

}

int main()
{
	for(int i=LOW_BOUND;i<=UP_BOUND;i++)
	{
		if(is_NarcissisticNumber(i))
		{
			printf("%d\n",i);
		} 
	}
	 
	return 0;
}
