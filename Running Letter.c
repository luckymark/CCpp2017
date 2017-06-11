#include <stdio.h>
#include <windows.h>

int main(int argc, char** argv)
{
	int i = 0;
	int j = 0;
	while (1)
	{
		printf("R");
		Sleep(30);
		system("cls");
		int op = 1;
		for (i = 0; i<79&&i>=0; i+=op)
		{
			for (j = 0; j < i; j++)
			{
				printf(" ");
			}
			printf("R");
			Sleep(30);
			system("cls");
			if (i == 78)
			{
				op = -1;
			}
			if (i == 0)
			{
				op = 1;
			}
		}
	}
	return 0;
}