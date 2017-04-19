#include <stdio.h>
int pow_3(int x){
	return x * x * x;
}
int main(){
	for(int i = 100; i <= 999; i++){
		int cur = pow_3( i % 10 ) + pow_3( (i/10) % 10 ) + pow_3( i / 100 );
		if(cur == i) 
			printf("%d\n", i);
	}
	return 0;
}
