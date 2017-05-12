#include<stdio.h>
void hanoi(int n, char a, char b, char c);
int main(void)
{
	printf("please input the number you want: ");
	int num;
	scanf_s("%d", &num);
	getchar();
	hanoi(num, 'a', 'b', 'c');
	getchar();
	return 0;
}

void hanoi(int n, char a, char b, char c)
{
	if (n == 1)
		printf("%d: %c>>%c\n", n, a, c);
	else {
		hanoi(n - 1, a, c, b);
		printf("%d :%c>>%c\n", n, a, c);
		hanoi(n - 1, b, a, c);
	}
}
