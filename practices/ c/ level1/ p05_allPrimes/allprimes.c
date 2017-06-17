#include<stdio.h>
#include<math.h>
#include<time.h>
int main()
{
	clock_t t1, t2;
	t1=clock();
	int i, j;
	int num[1001] = {0};
	for (i = 2; i <= 1000; i++) {
		for (j = 2 * i; j <= 1000; j += i) {
			num[j] = 1;
		}
	}
	for (i = 2; i <= 1000; i++) {
		if (num[i] == 0) {
			printf("%d\t", i);
		}
	}
	t2 = clock();
	printf("\n%d\n", t2 - t1);
return 0;
}
