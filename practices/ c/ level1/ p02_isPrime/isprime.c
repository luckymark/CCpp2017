#include<stdio.h>
#include<math.h>
int is_prime(int a);
int main()
{
	int x;
	scanf_s("%d", &x);
	if (is_prime(x)) {
		printf("%d is a prime", x);
	}
	else {
		printf("%d is not a prime", x);
	}
	return 0;
}

int is_prime(int a)
{
	int k;
	if (a == 1) {
		return 0;
	}if (a == 2) {
		return 1;
	}if (a > 2) {
		for (k = 2; k <= sqrt(a); k++) {
			if (a%k == 0) {
				return 0;
				break;
			}
			else {
				return 1;
			}
		}
	}
}
