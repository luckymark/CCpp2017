#include<stdio.h>
#include<time.h>
int main()
{
	int n=5,i,j;
	printf("%d %d",2,3);
	for(;n<1001;n+=2,j=0)
	{
		for(i=2;i<n;i++)
		{
			if(n%i==0)
			{
				j=1;
				break;
			}
			
		}
		if(j!=1)printf(" %d",n);
		//else printf(" %d",n);
		//if(i==n-1)printf(" %d",n);
	}
	printf("\n%d millisceonds",clock());
	return 0;
} 
