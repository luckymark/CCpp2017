#include<stdio.h>

int main()
{
	printf("     2");
	for (int i = 2;i <= 1000;i++)
	{
		int j = 2;
		while (i > j) {
			if (i%j == 0) {
				break;
			}
			else {
				if (i == j + 1) {
					printf("%5d", i);
					break;
				}
				j++;

			}
		}
	}
}