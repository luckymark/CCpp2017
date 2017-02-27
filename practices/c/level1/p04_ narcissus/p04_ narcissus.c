//打印三位水仙花数
#include <stdio.h>
int main(void)
{
	int i;
	int a,b,c;
	for (i=100;i<999;i++){
		c=i%10;
		b=((i-c)/10)%10;
		a=(i-b*10-c)/100;
		c=c*c*c;
		a=a*a*a;
		b=b*b*b;
		if (a+b+c==i)
		printf("%d   ",i);
	}
 } 
