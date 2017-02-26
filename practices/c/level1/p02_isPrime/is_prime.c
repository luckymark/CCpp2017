#include <stdio.h>
#include <math.h>

int main(void)
{
	int n, i;
	int middle;
	
	scanf("%d", &n);
	middle = sqrt(n);
	for (i = 2; i < middle; i++){
		if (n % i == 0){
			printf("%d is not prime\n", n);
			return 0;
		}
	}
	printf("%d is prime\n", n);
	
	return 0;	
}
