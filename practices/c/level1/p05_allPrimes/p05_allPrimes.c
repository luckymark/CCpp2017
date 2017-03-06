#include <stdio.h>
#include <time.h>
#include <math.h>
#define n 100
int main()
{
	clock_t t1,t2;
	t1 = clock();
	int nums[n+2] = {0};
	for(int i=1;i<=n;i++)
	{
		nums[i]=i;
	}
	
	for(int i=2;i<n+1;i++)
	{
		if(nums[i] != 0)
		{
			for(int j=2*i;j<n+1;j+=i)
			{
				nums[j]=0;
			}
		}
	}
	for(int i=2; i<n+1; i++)
	{
		if(nums[i] != 0)
		{
			printf("%d ",nums[i]);
		 } 
	}
	
	t2 = clock();
	printf("\n%dms uesd",t2-t1);
	return 0;
}

