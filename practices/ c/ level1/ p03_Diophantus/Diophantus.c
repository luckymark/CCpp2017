#include<stdio.h>
int main()
{
	int x;
	for (x = 1; x <= 150; x++) {
		if (x*(1 / 6.0 + 1 / 7.0 + 1 / 12.0) + 5 + x / 2.0 + 4 == x) {
			printf("%d", x-4);
		}
	}
	return 0;
}
