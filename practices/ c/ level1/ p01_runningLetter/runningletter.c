#include<stdio.h>
#include<windows.h>
int for_back_word(int a);
const int n = 120;
int main()
{
	int i;
	for (i = 1; i < n; i++) {
		for_back_word(i);
	}
	for (i; i > 0; i--) {
		for_back_word(i);
	}
	return 0;
}

int for_back_word(int a)
{
	int j,m=100;
	for (j = 1; j < a; j++) {
		printf(" ");
	}
	printf("R");
	Sleep(m);
	system("cls");
}
