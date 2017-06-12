#include<stdio.h>
#include<math.h>

int isPrime(int);
int main()
{
	for(int n=4;n<=100;n+=2){
		for(int i=2;i<=n/2;i++){
			if(isPrime(i)&&isPrime(n-i)){
				printf("%d=%d+%d\n",n,i,n-i);
				break;
			}
		}
	}
	return 0;
} 
int isPrime(int n)
{
	if(n<2){
		return 0;
	}
	if(n==2){
		return 1;
	}
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
	
}
