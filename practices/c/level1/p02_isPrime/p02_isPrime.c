#include <stdio.h>
int main(void)
{
	int num,i,j;
	printf("Please enter a interger to calculate.\n");
	printf("Enter q to quit.\n");
	while (scanf("%d",&num)){
		j=sqrt(num);
		for (i=2;i*i<=num;i++){
			if (num%i==0){
				printf("%d is not a primer.\n",num);
				break;
			}}
			if (i*i>num){
				printf("%d is a primer.\n",num);
			}
			printf("Please enter next interger.\n");
			
	}
	return 0;
		
}
