#include<stdio.h>
#include<windows.h>
int main()
{
	char n[50];
	for(int i=0;i<50;i++){
		n[i]=' ';
	}
	n[0]='R';
	for(int i=1;i<50;i++){
		n[i]='R';
		n[i-1]=' ';
		for(int j=0;j<50;j++){
			printf("%c",n[j]);
		}
		Sleep(15);
		system("cls");
	}
	for(int i=48;i>=0;i--){
		n[i]='R';
		n[i+1]=' ';
		for(int j=0;j<50;j++){
			printf("%c",n[j]);
		}
		Sleep(15);
		system("cls");
	}
	
	return 0;
} 
