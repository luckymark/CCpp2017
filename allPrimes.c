#include<stdio.h>
#include<time.h>

#define MAXP 1001

int isNotPrime[MAXP+10];
int num_prime,prime[MAXP+10];

void Eratosthenes();

int main(){
	int t=clock();
	Eratosthenes();
	printf("%d\n",clock()-t);
	return 0;
}

void Eratosthenes(){
	for(int i=2;i<MAXP;i++){
		if(!isNotPrime[i]){
    		prime[num_prime++]=i;
		}
    	for(int j=0;j<num_prime && i*prime[j]<MAXP;++j){
			isNotPrime[i*prime[j]]=1;
			if(!(i%prime[j])){
				break;
			}
		}
	}
	for(int i=0;i<num_prime;++i)
		printf("%d\n",prime[i]);
}
