#include<stdio.h>
void han(int num, char a, char b, char c);

int main()
{
	int num;
	printf("�����������ƶ��ĺ�ŵ��Բ��������");
	scanf_s("%d", &num);
	printf("�ƶ�˳��Ϊ��\n");
	han(num, 'a',' b',' c');
}

void han(int num, char a, char b, char c)
{
	if (num == 1) {
		printf("%c�ƶ���%c\n", a, c);
	}
	else {
		han(num - 1, 'a',' c', 'b');
		printf("%c�ƶ���%c\n", a, c);
		han(num - 1, 'b', 'a', 'c');
	}
}