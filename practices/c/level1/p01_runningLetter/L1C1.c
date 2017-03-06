#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
int main(){
	int n = 0;
	bool flag = 1;
	while(1)
	{
		system("cls");
		for(int i=0; i<n; i++) {
			printf(" ");
		}
		printf("R");	
		if(flag){
			n++;
			if(n==50){
				flag=0;
			}
		}
		else{
			n--;
			if(n==0) {
				flag=1;
			}
		}
	}
	return 0;
}
