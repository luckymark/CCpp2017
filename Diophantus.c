#include<stdio.h>

int main(){
	for(int i=1;;++i){
		if(i%6!=0 || i%12!=0 || i%7!=0 || i%2!=0){
			continue;
		}
		if(i/6 + i/12 + i/7 + 5 + i/2 + 4 == i){
			printf("%d\n",i-4);
			break;
		}
	}
	return 0;
}
