#include <stdio.h>

void move(int n , char a, char b, char c);

int main (void)
{
	int n;

	printf("Enter the number of disk to be moved: ");
	scanf("%d", &n);
	if(n <= 0){
		printf("Illegal input\n");
	}
	else{
		move(n, 'A', 'B', 'C');
	}
		
	return 0;
}

void move(int n, char a, char b, char c)
{
	if (n ==  1){
		printf("Move disk %d from %c to %c\n", n, a, c);
	}
	else{
		move(n - 1, a, c, b);
		printf("move disk %d from %c to %c\n", n, a, c);
		move(n - 1, b, a, c);
	}
}
