#include <stdio.h>
void move(char a,char b,char c,int n);
int main()
{
	int n =4;
	char a='a' , b='b' , c='c';
	move(a,b,c,n);
}

void move(char a,char b,char c,int n)   //该函数把n个碟片从a柱移到c柱 
{
	if(n==1)
	{
		printf("%c-->%c\n",a,c);   //如果只有一个碟片直接输出a-->c 
	}
	else
	{
		move(a,c,b,n-1);      			//首先把上面的n-1个碟片移到b柱 
		printf("%c-->%c\n",a,c);     //再把第n个移到c柱 
		move(b,a,c,n-1);			//最后再把在b柱的n-1个移到c柱 
	}
}
