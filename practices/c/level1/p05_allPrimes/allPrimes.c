#include<stdio.h>
#include <time.h>

int main()
{
	clock_t start, finish;
	double duration;

	start = clock();
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
	finish = clock();
	duration = (finish - start)*1.0 / CLOCKS_PER_SEC;
	printf("\n程序运行时间为：%lfs", duration);
}