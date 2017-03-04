#include <stdio.h>
int main(){
		for(int i = 0; i <= 200; i+=7*12){
				if(2 * ( (i - 4) - (i / 7 + i / 6 + i / 12 + 5)) == i){
						printf("%d\n", i - 4);
				}
		}
		return 0;
}
