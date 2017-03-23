#include <stdio.h>
void Hanoi(char a, char b, char c, int n);
int main()
{
	freopen("out.txt", "w", stdout);
	Hanoi('A', 'B', 'C', 3);
	return 0;
}
void Hanoi(char a, char b, char c, int n)
{
	if (n == 1)
	{
		printf("Move %d disk from %c to %c\n", n, a, c);
		return;
	}
	Hanoi(a, c, b, n - 1);
	printf("Move %d disk from %c to %c\n", n, a, c);
	Hanoi(b, a, c, n - 1);
}
