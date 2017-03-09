#include<stdio.h>
int main()
{
	int i,j;
	printf("*\t");
	for(int a=1;a<=9;a++)
	{
		printf("%d\t",a);
	}
	printf("\n");
	for(i=1;i<=9;i++)
	{
		printf("%d\t",i);
		for(j=1;j<=i;j++)
		{
			printf("%d\t",i*j);
		}
		printf("\n");
	}
	return 0;
} 
