#include<stdio.h>

void narcissus(void);

int main(void)
{
	narcissus();
	
	return 0;
}
void narcissus(void)
{
	int i;
	int a,b,c;
	
	for(i=100;i<1000;i++)
	{
		a=i/100;
		b=(i-a*100)/10;
		c=i-a*100-b*10;
		if(i==a*a*a+b*b*b+c*c*c)
		{
			printf("%d\t",i);	
		}
	}
	
}
