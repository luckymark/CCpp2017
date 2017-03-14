#include<stdio.h>
void han(int num, char a, char b, char c);

int main()
{
	int num;
	printf("请输入您想移动的汉诺塔圆环个数：");
	scanf_s("%d", &num);
	printf("移动顺序为：\n");
	han(num, 'a',' b',' c');
}

void han(int num, char a, char b, char c)
{
	if (num == 1) {
		printf("%c移动到%c\n", a, c);
	}
	else {
		han(num - 1, 'a',' c', 'b');
		printf("%c移动到%c\n", a, c);
		han(num - 1, 'b', 'a', 'c');
	}
}