#include<stdio.h>

bool isPrimes(int n);

int main()
{
	int m,n;
	int num = 0;
	
	for(int i = 2 ; i < 98 ; i = i+2){
		for(n = 1 ; n < i ; n++){
			
			int truth = 0;
			m = i-n;
			
			if(isPrimes(n)&&isPrimes(m)){
				truth = 1;
				if(truth == 1){
					num++;
					break;
				}
			}
			
		}
	}
	if(num == 48){
		printf("this propersition is right");
	}
	return 0;
 } 

bool isPrimes(int n)
{
	for(int i = 2 ; i < n ; i++){
		if(n%i == 0){
			return false;
		}
	} 
	return true;
}
