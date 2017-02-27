#include<stdio.h>
int main(){
 	int number;
 	int hundred,ten,one;
 	for (number=100;number<=999;number++){
 		hundred=number/100;
 		ten=(number/10)%10;
 		one=number%10;
 		if (number==hundred*hundred*hundred+ten*ten*ten+one*one*one){
			printf("%d\n",number);
		}
	}
	return 0;
 }
