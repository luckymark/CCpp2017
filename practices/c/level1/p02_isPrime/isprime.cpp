#include<stdio.h>
int main()
{
	int n,i,k=0;
	scanf("%d",&n);
	if(n<=1)printf(" not prime number");
	else
	{
		for(i=2;i<n;i++)
		{
			if(n%i==0)
			{ 
				k=1;
				printf("not prime number");
				break;
			}
		}
		if(k==0)printf("prime number");
	}
	return 0;
}
