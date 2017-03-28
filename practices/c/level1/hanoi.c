#include<stdio.h>

void move(int n,int x,int y,int z)
{
	if(n==1)
	{
		printf("%c->%c\n",x,z);
	}
	else
	{
		move(n-1,x,z,y);
		printf("%c->%c\n",x,z);
		move(n-1,y,x,z);
	}
}
void main()
{
	int h; 
	printf("\ninputnumber:\n");
	scanf("%d",&h);
	printf("the step to moving %2d diskes:\n",h);
	move(h,'a','b','c');
}
