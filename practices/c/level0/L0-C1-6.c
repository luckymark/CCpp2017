#include<stdio.h>
int main()
{
	int number[1000];
	int max=0;
	int i;
	for (i=0;i<1000;i++)
	{
		scanf("%d",&number[i]);
		if(max<number[i])
		{
			max=number[i];
		}
	}
	printf("最大的数是%d",max);
	return 0;
} 
