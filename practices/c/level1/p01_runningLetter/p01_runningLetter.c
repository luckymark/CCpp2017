#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

int main()
{
	bool flag =true;
	int size = 20;
	int n = 0;
	while(true)
	{
		system("cls");
		
		if(flag)
			n++;
		else
			n--;
		if(n>=size)
			flag = false;
		if(n<=0)
			flag = true;
		for( int i=0;i<=n;i++)
			printf(" ");
		printf("#\n");
		Sleep(100);
	}
}
