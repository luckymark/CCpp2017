#include<stdio.h>
#include<windows.h>
main()
{
	for(int i=1;i<=50;i++){
		for(int j=1;j<=i;j++){
			printf(" ");
		}
		printf("R");
		Sleep(10);
		system("cls");
	}
	for(int i=50;i>=1;i--){
		for(int j=i;j>=1;j--){
			printf(" ");
		}
		printf("R");
		Sleep(10);
		system("cls");
	}
}
