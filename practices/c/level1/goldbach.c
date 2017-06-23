#include<stdio.h>
int sushu(int a)
{
	int b, c=0;
	for(b=2;b<a;b++)
	{
	    if(a%b!=0)
	    c++;
	}
	if(c==a-2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int i,j;
	for(i=4;i<=100;i+=2)
	{
		for(j=2;j<=i/2;j++)
		{
			if(sushu(j)&&sushu(i-j))
			printf("%d=%d+%d\t",i,j,i-j);
		}
	}
	return 0;
}

