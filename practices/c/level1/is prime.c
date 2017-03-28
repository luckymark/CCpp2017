#include<stdio.h>
int main()
{
	int a,i,b;
	b=0;
	printf("print the letter£º");
	scanf("%d",&a);
	for(i=2;i<a;i++)
	{
		if(a%i!=0)
		b++;
	}
	if(b==a-2)
	{
		printf("a is prime"); 
	}
	else
	{
		printf("a isnt prime");
	}
}
