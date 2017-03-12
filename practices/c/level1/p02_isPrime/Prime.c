#include <math.h>
#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int i;
	for (i = 2; i <= trunc(sqrt(n)); i++)
		if (n % i == 0)
		{
			puts("It is not a prime.");
			return 0;
		}
	puts("It is a prime.");
	return 0;
}
