#include<stdio.h>
int main(void)
{
	for (int i = 10; i <= 100; ++i)
	{
		if (84 * i == 84 * 9 + 75 * i) {
			printf("when his son died his age is %d", i - 4);
			getchar();
			return 0;
		}

	}
	return 0;
}