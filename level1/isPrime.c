#include <stdio.h>
#include <math.h>

int main()
{
	int i,num;

	printf("\nPlease enter a number: ");
	scanf("%d",&num);
	if (num == 2)
		printf("\nIt's a prime.\n");
	else{
		for (i=2; i<=sqrt(num); i=i+2){
			if (num % i==0){
				printf("\nIt's not a prime.\n");
				break;
			}
		}
		if (i > sqrt(num))
			printf("\nIt's a prime.\n");
	}
	return 0;
}
