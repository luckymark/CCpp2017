#include<stdio.h>

int jc(int a)
{
	int b=1,i;
	for(i=1;i<=a;i++)
	{
		b*=i;
	}
	return b;
 } 
void main()

{
 	int x,y;
	printf("¨º?¨¨???¨ºy¡êo");
 	scanf("%d",&x);
 	y=jc(x);
 	printf("jc=%d",y);
}

