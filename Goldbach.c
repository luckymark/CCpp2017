#include<stdio.h>
#include<time.h>

int is_prime(int x);

int main(){
	for(int i=4;i<=100;i+=2){
		for(int j=1;j<=i;++j)
			if(is_prime(j) && is_prime(i-j)){
				printf("%d = %d + %d\n",i,j,i-j);
				break;
			}
	}
	return 0;
}

int is_prime(int x){
	if(x==1 || x==0){
		return 0;
	}
	for(int i=2;i*i<=x;++i){
		if(x%i==0){
			return 0;
		}
	}
	return 1;
}
