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
	printf("请选择您是想加密还是解密:a、加密     b、解密\n");
	k = getch();
	if (k == 'a') {
		encrypt();
	}


	else if (k == 'b') {
		decrypt();
	}
	else {
		printf("您输入的信息有误.");
		return 0;
	}
}


void encrypt()
{
	printf("请输入您想加密的字符串: ");
	do
	{
		ch = getchar();
		count++;
		if (count >= L) {
			p = (char*)realloc(p, sizeof(char*) * (++L));
		}
		p[count - 1] = (char)((int)ch + 4);
	} while (ch != '\n');
	printf("您一共输入%d个字符\n加密后的密文为：", count - 1);
	for (int i = 0;i < count;i++) {
		printf("%c", p[i]);
	}
	free(p);
}


void decrypt()
{
	printf("请输入您想解密的字符串: ");
	do
	{
		ch = getchar();
		count++;
		if (count >= L) {
			p = (char*)realloc(p, sizeof(char*) * (++L));
		}
		p[count - 1] = (char)((int)ch - 4);
	} while (ch != '\n');
	printf("您一共输入%d个字符\n解密后的密文为：", count - 1);
	for (int i = 0;i < count;i++) {
		printf("%c", p[i]);
	}
	free(p);
}