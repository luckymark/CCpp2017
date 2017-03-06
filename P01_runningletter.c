#include<stdio.h>
#include<windows.h>
#define SPACE 50

void show(char *pos);

int main()
{
	char pos[102] = { " " };
	
	for(int i=0;i<100;i++)
	{
		pos[i] = 'R';
		show(pos);
		pos[i] = ' ';
		if(i==99)			//字母碰到边界时变为递减
			for(;i>=0;i--)
			{
				pos[i] = 'R';
				show(pos);
				pos[i] = ' ';
			}
	}
	return 0;
}
void show(char *pos) {
	printf("%s", pos);
	Sleep(SPACE);
	system("cls");
}
