#include<stdio.h>
int main()
{
	int number[1000];
	int i;
	for(i=0;i<=999;i++){
		scanf("%d",&number[i]);
	}
	int count=0;
	for(i=999;i>=0;i--){
		printf("%3d",number[i]);
		count++;
		if(count%5==0){
			printf("\n");
		}
	}
	return 0; 
} 
