//Goldbach:任一大于2的偶数都可写成两个质数之和
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int i, j;
	int k;
	int m, n;
	int num[101] = {0};
	for (i = 2; i < 51; i++) {
		for (j = 2 * i; j < 101; j += i){
			num[j] = 1;
		}
	}
	for (k = 4; k < 101; k += 2) {
		for (m = 2; m < 101; m++) {
			for (n = 2; n < 101; n++) {
				if (num[m] == 0 && num[n] == 0 && m + n == k) {
					printf("%d=%d+%d\n", k, m, n);
				}
			}
		}
	}
	system("pause");
	return 0;
}
