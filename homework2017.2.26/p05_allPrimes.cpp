#include<stdio.h>
#include<string.h>
#include<time.h>
int main(){
 	int i,j=2,prime[1000],numb;
 	clock_t start,endd;
	start=clock();
	memset(prime,0,sizeof(prime));
	prime[1]=2;
 	printf("%d\n",prime[1]);
 	for (numb=3;numb<=1000;numb++){
 		for (i=1;prime[i]*prime[i]<=numb&&prime[i];i++){
			if (numb%prime[i]==0){
				break;
			}
		}
		if(prime[i]*prime[i]>numb){
			prime[j++]=numb;
		 	printf("%d\n",numb);
		}
	}
	endd=clock();
	printf("The algorithm costs %.0lfms;\n",(double)(endd-start));
	printf("It will costs 0.01ms without printf().\n");
 	return 0;
}
