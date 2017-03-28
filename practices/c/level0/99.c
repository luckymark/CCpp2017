#include<stdio.h>

void main()
{
	int a,b,c;
	printf("   *");
	for(a=1;a<=9;a++)
	{
	printf("%4d",a);
	}
	printf("\n");
	for(a=1;a<=9;a++)
	{
		printf("%4d",a);
		for(b=1;b<=a;b++)
		{
			c=a*b;
			printf("%4d",c);
		}
		printf("\n");
	}
	
}
