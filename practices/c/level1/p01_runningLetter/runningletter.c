#include<stdio.h>
#include<windows.h>
#include<stdbool.h>

void running(int col);

int main(void){
	system("mode con cols=63");
	running(63);
	
	return 0;
} 
void running(int col){
	int i=0,j;
	bool flag=0;
	
	while(1){
		Sleep(50);
		system("cls");
		for(j=0;j<i;j++){
			printf(" ");
		}
		if(!flag){
			i++;
		}
		else{
			i--;
		}
		if(62==i||0==i){
			flag=!flag;
		}
		putchar('R');
	    	    
	}
}
