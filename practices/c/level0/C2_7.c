#include <stdio.h>

int main()
{
	int string[10]={0};
	int i,j,k;
	
	printf("\t");
	
	for(i=1;i<10;i++)
	{
		string[i]=i;
		printf("%d\t",string[i]);
	}
	
	printf("\n");
	
	for(j=1;j<10;j++)
	{
		printf("%d\t",string[j]);
		for(k=1;k<=j;k++)
		{
			printf("%d\t",string[j]*string[k]);
		}
		printf("\n");
	}
	
	return 0;
}
