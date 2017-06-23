#include<stdio.h>
void main()
{
	int a;
	for(a=1;a<=100;a++)
	{
		if(a%3==0&&a%5!=0)
		printf("%d\n",a);
	}
}
