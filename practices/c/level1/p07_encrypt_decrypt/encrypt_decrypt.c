#include<stdio.h>
#include<stdlib.h>
void encrypt();
void decrypt();

int L = 5;
char k, ch;
char* p;
int count = 0;

int main()
{
	p = (char*)malloc(sizeof(char) * L);
	printf("��ѡ����������ܻ��ǽ���:a������     b������\n");
	k = getch();
	if (k == 'a') {
		encrypt();
	}


	else if (k == 'b') {
		decrypt();
	}
	else {
		printf("���������Ϣ����.");
		return 0;
	}
}


void encrypt()
{
	printf("������������ܵ��ַ���: ");
	do
	{
		ch = getchar();
		count++;
		if (count >= L) {
			p = (char*)realloc(p, sizeof(char*) * (++L));
		}
		p[count - 1] = (char)((int)ch + 4);
	} while (ch != '\n');
	printf("��һ������%d���ַ�\n���ܺ������Ϊ��", count - 1);
	for (int i = 0;i < count;i++) {
		printf("%c", p[i]);
	}
	free(p);
}


void decrypt()
{
	printf("������������ܵ��ַ���: ");
	do
	{
		ch = getchar();
		count++;
		if (count >= L) {
			p = (char*)realloc(p, sizeof(char*) * (++L));
		}
		p[count - 1] = (char)((int)ch - 4);
	} while (ch != '\n');
	printf("��һ������%d���ַ�\n���ܺ������Ϊ��", count - 1);
	for (int i = 0;i < count;i++) {
		printf("%c", p[i]);
	}
	free(p);
}