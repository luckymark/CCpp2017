#include<stdio.h>
#include<stdlib.h>

int main()
{
	int L = 5;
	int i;
	char k, ch;
	char* p = (char*)malloc(sizeof(char) * L);
	int count = 0;
	printf("��ѡ����������ܻ��ǽ���:a������     b������\n");
	k = getch();
	if (k == 'a') {
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
		for (i = 0;i < count;i++) {
			printf("%c", p[i]);
		}
		free(p);
	}


	else if (k == 'b') {
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
		for (i = 0;i < count;i++) {
			printf("%c", p[i]);
		}
		free(p);
	}
	else {
		printf("���������Ϣ����.");
		return 0;
	}
}

