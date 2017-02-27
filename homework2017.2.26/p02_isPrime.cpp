#include<stdio.h>
int main(){
	int number,i;
	while (scanf("%d",&number)!=EOF){	
		if (number==0){
			break;
		}
		for (i=2;i*i<=number;i++){
			if (number%i==0){
				break;
			}
		}
		if (i*i>number){
			printf("Yes\n");	
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}