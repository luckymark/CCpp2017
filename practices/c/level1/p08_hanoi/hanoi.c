#include<stdio.h>

void hanoi(int n,char a,char b,char c);
void move(char x,char y);

int main()
{
	int m;
	printf("input the number of diskes:");
	scanf("%d",&m);
	hanoi(m,'A','B','C');
		
	return 0;
}


void hanoi(int n,char a,char b,char c)
{
	if(n==1){
		move(a,c);
	}else{
		hanoi(n-1,a,c,b);
		move(a,c);
		hanoi(n-1,b,a,c);
	}
} 

void move(char x,char y)
{
	printf("%c-->%c\n",x,y);
}
