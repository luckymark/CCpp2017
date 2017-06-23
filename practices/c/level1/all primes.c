#include<stdio.h>
int main()
{
	int a,b,c;
	printf("primes from 2-1000£º2\t");
	for(a=3;a<=1000;a++)
	{
		c=0;
		for(b=2;b<a;b++)
		{
			if(a%b!=0)
			c++;
		}
		if(c==a-2)
		{
			printf("%d\t",a);
		}
	}
}
