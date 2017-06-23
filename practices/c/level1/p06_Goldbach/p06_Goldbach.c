#include <stdio.h>
#include <math.h>
#define N 101

int isPrime(int x);
void init();

struct Data {
    int a,b,c;
}a[N];

int primes[20];
int numberOfPrimes;

int main() {
	init();
	for (int i = 0; i < numberOfPrimes; i++) {
		for (int j = i; j < numberOfPrimes; j++) {
			int k = primes[i] + primes[j];
			if (k > 100) {
				break;
			}
			a[k].a = primes[i];
			a[k].b = primes[j];
		}
	}

	for (int i = 0; i < numberOfPrimes; i++) {
		for (int j = i; j < numberOfPrimes; j++) {
			for (int k = j; k < numberOfPrimes; k++) {
				int x = primes[i] + primes[j] + primes[k];
				if (x > 100) {
					break;
				}
				a[x].a = primes[i];
				a[x].b = primes[j];
				a[x].c = primes[k];
			}
		}
	}
	
	printf("不小于6的偶数都是两个素数之和：\n");
	for (int i = 6; i <= 100; i+=2) {
		printf("%d = %d + %d\n",i,a[i].a,a[i].b);
	}
	printf("不小于9的偶数都是三个素数之和：\n");
	for (int i = 9; i < 100; i+=2) {
		printf("%d = %d + %d + %d\n",i,a[i].a,a[i].b,a[i].c);
	}
	return 0;
}
    
int isPrime(int x) {
    for (int i = 2; i <= sqrt(x); i++) {
        if (x%i == 0) return 0;
    }
    return 1;
}

void init() {
    numberOfPrimes = 0;
    for (int i = 3; i < 100; i++) {
        if (isPrime(i)) {
            primes[numberOfPrimes++] = i;
        }
    }
}
