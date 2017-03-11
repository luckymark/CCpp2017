#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


int main() {
	system("mode con cols=80 lines=20");
	int x = 0, y = 0, mark = 0;
	while (1)
	{
		int i;
		for (i = 0; i < x; i++)
		{
			printf(" ");
		}
		printf("r");
		(mark % 2 == 0) ? x++ : x--;
		if (x == 0 || x == 80)
		{
			mark++;
		}
		Sleep(30);
		system("cls");

	}
	system("pause");
	return 0;
}

