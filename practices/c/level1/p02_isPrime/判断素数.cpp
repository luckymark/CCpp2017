#include<stdio.h>

int main(void)
{
	int num_judge;
	scanf("%d",&num_judge);
	if(num_judge<=3){
		printf("yes %d is.",num_judge);
		return 0;
	}
	int i;
	int k=num_judge-1;
	for(i=4;i<=k;i++){
		if(num_judge%i==0){
			printf("no, %d isn't!",num_judge);
			return 0;
		}
	}
	printf("yes %d is ",num_judge);
	return 0;
}