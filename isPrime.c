#include<stdio.h>

int is_prime(int x);

int main(){
	int n;
	scanf("%d",&n);
	puts(is_prime(n) ? "YES" : "NO");
	return 0;
}

int is_prime(int x){
	if(x==1){
		return 0;
	}
	for(int i=2;i*i<=x;++i){
		if(x%i==0){
			return 0;
		}
	}
	return 1;
}
