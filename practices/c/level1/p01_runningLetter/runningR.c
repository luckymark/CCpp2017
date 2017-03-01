#include<stdio.h>
#include<windows.h>
void main()
{
	int i,j;
	for (i = 0;i < 80;i++){
		Sleep(50);
		system("cls");
		for (j = 0;j < i - 1;j++) {
			printf(" ");
		}
		printf("R");

	}
	for (i = 80;i >= 0;i--){
		Sleep(50);
		system("cls");
		for (j = 0;j < i - 1;j++){
			printf(" ");
		}
		printf("R");
	}
	return 0;
}