#include <stdio.h>
#define n 10

int main()
{
	int num;
	int max=0;
	
	for (int i=0;i<=n;i++)
	{
		printf("Input a number and press ENTER: ");
		scanf("%d",&num);
		if(max<=num)
		{
			max=num;
		}
	}
	printf("The biggest number is %d",max);
	return 0;
}
