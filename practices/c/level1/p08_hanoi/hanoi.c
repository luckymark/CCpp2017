#include<stdio.h>
void hanoi(int n,char A,char B,char C);
int main()
{
	int n;
	puts("How much plate you need to move?");
	scanf("%d",&n);
	hanoi(n,'A','B','C');
	return 0;
} 
void hanoi(int n,char A,char B,char C)
{
	if(n==1)printf("%c->%c ",A,C);
	else
	{
		hanoi(n-1,A,C,B);
		printf("%c->%c\ ",A,C);
		hanoi(n-1,B,A,C);
	}
}
