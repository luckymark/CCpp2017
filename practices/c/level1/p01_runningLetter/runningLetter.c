#include<stdio.h>
#include<Windows.h>

int main()
{
	int n = 0, pos=0;

	while (TRUE)
	{
		if (n>30)
		{
			pos = 60 - n;
		}
		else
		{
			pos = n;
		}
		for (int i = 0; i<pos; i++)
		{
			putchar(' ');
		}
		putchar('R');
		n++;
		if (n == 60)
		{
			n = 0;
		}
		Sleep(50);
		system("cls");
	}
	return 0;
}
