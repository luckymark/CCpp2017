#include <stdio.h>
int main(void)
{
	long long  num;
	long long  i;
	printf("Please enter a interger to calculate.\n");
	printf("Enter q to quit.\n");
	while (scanf("%lld",&num)){
		for (i=2;i*i<=num;i++){
			if (num%i==0){
				printf("%lld is not a primer.\n",num);
				break;
			}}
			if (i*i>num){
				printf("%lld is a primer.\n",num);
			}
			printf("Please enter next interger.\n");
			
	}
	return 0;
		
}
