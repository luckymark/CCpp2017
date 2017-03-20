#include<stdio.h>

void move_record(int n, char a, char b, char c);

int main()
{
	int n;
	scanf("%d", &n);
	move_record(n, 'a', 'b', 'c');
	return 0;
}

void move_record(int n, char a, char b, char c)
{
	if(n == 1)
	printf("%c -> %c\n", a, c);
	else
	{
		move_record(n-1, a ,c ,b);
		printf("%c -> %c\n", a, c);
		move_record(n-1, b, a ,c);
	}
}
