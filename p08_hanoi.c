#include<stdio.h>
#include<stdlib.h>
#define WIDTH 11

void hanoi(char a, char b, char c, int n);
int step = 0;

void main()
{
	freopen_s("out.txt", "w", stdout);
	hanoi('A','B','C',WIDTH);
	printf("%d steps", step);
	system("pause");
}
void hanoi(char a, char b, char c, int n)
{
	if (n == 1)
	{
		printf("move %d from %c to %c\n", n, a, c);
		step++;
		return;
	}
	hanoi(a, c, b, n - 1);
	printf("move %d from %c to %c\n", n, a, c);
	step++;
	hanoi(b, a, c, n - 1);
}
