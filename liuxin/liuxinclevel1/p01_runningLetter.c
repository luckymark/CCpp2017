#include <stdio.h>
#include <windows.h>
int main(){
	int i,j=0,k=1;
	while (1) {
		system("cls");
		for (i=1;i<=j;++i) {
			putchar(' ');
		}
		printf("R\n");
		Sleep(100);
		if (k) {
			j++;
		}else{
			j--;
		}
		if (j==79) {
			k=0; 
		}
		else if (j==0) {
			k=1;
		}
	}
	return 0;
}

/*
Ugly format
*/
