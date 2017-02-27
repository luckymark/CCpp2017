#include <stdio.h>
void move(char,char); 
int hannuo(int n,char A, char B, char C); 
int main(int argc, char *argv[])
{
	int n;
	char A, B, C;
	A = 65;
	B = 66;
	C = 67;
	printf("enter the number of plates you want\n");
	scanf("%d", &n);
	hannuo(n, A, B, C);
	getchar();
	getchar();
	return 0;
}
int hannuo(int n,char A, char B, char C)
{
	if (n == 2)
	{
		move(A, B);
		move(A, C);
		move(B, C);
	}
	else
	{
		hannuo(n - 1, A, C, B);
		move(A, C);
		hannuo(n - 1, B, A, C);
	}
}
void move(char A, char B)
{
	printf("%c->%c\n", A, B);
}
