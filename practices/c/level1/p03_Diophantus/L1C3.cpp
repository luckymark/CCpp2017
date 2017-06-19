#include <stdio.h>
int main(){
	for(double i=0; i < 100; i++){
		if(i/6+i/12+i/7+5+i/2+4 == i){
			printf("%.0lf", i-4);
			return 0;
		}
	}
	return 0;
}

