#include<stdio.h>

int main(){
  	int i,j=2,numb,prime[100];
 	prime[1]=2;
 	for (numb=3;numb<=100;numb++){
 		for (i=1;prime[i]*prime[i]<=numb&&prime[i];i++){
			if (numb%prime[i]==0)	break;			
		}
		if(prime[i]*prime[i]>numb){
			prime[j++]=numb;			
		}
	}
	for (numb=4;numb<=100;numb+=2){
		for (i=1;prime[i]!=0;i++){
			for (j=1;prime[j]!=0;j++){
				if (prime[j]+prime[i]==numb){
					break;		
				}			
			}
			if (prime[j]==0){
				break;	
			}
		}
		if (prime[i]==0&&prime[j]==0){
			break;
		}
	}
	if (numb>100){
		printf("proved\n");
	}
	else{
		printf("not");	
	}
	return 0;
}
