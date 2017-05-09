#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#define SIZE 20 
#define SLEEP_TIME 100
int main()
{
	bool flag =true;
	int n = 0;
	while(true)
	{
		system("cls");
		n=flag ? n+1:n-1;
		flag = n>=SIZE ? false:flag;
		flag = n<=0 ? true:flag;
		for( int i=0;i<=n;i++)
		{
			printf(" ");
		}
		printf("#\n");
		Sleep(SLEEP_TIME);
	}
}
