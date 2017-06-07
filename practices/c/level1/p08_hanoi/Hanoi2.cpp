// Hanoi2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
void hanoi(int n, char from, char by, char to);
void move (char from, char to);

int main()
{
	int n;
	printf("���������ӵĸ�����");
	scanf("%d", &n);
	hanoi(n, 'A', 'B', 'C');
    return 0;
}

void hanoi(int n, char from, char by, char to)
{
	if (n == 1)
	{
		move(by, to);
		return;
	}
	hanoi(n - 1, from, to, by);
	move(from, to);
	hanoi(n - 1, by, from, to);
}

void move(char from, char to)
{
	printf("%c->%c\n", from, to);
}
