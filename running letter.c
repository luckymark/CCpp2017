#include<stdio.h>
#include<windows.h>
#define space 50
void show(char *);
int main() {
	char pos[102] = { " " };
	int i=0;
	while (i < 100) 
	{
		pos[i] = 'R';
		show(pos);
		pos[i] = ' ';
		i++;
		if(i==100)			//��ĸ���߽�ʱ��Ϊ�ݼ�
			while(i>0)
			{
				pos[i] = 'R';
				show(pos);
				pos[i] = ' ';
				i--;
			}
	}
	
	return 0;
}
void show(char *pos) {
	printf("%s", pos);
	Sleep(space);
	system("cls");
}
