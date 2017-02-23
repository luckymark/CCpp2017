#include<stdio.h>
int main(void)
{
	int a,b,c,d,e,i;
	for(i=100;i<1000;i++)
	{
		b=i/100;
		c=(i-b*100)/10;
		d=(i-b*100-c*10);
		e=d*d*d+b*b*b+c*c*c;
		if(e==i)printf("%d\n",i);	
	}
	return 0;
}
