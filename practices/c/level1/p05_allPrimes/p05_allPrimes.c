#include <stdio.h>
#include <string.h>
#define N 1001

int isPrime[N];

void init() {
	memset(isPrime,1,sizeof(isPrime));
	for (int i = 2; i < N; i++) {
		if (isPrime[i]) {
			for (int j = 2; i*j < N; j++) {
				isPrime[i*j] = 0;
			}
		}
	}
}

int main() {
	init();
	for (int i = 2; i < N; i++) {
		if (isPrime[i]) printf("%d\t",i);
	}
	return 0;
}
