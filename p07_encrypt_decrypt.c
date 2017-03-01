#include<stdio.h>
#include<stdlib.h>
#define WIDTH 500
void encrypt(char* pt, int* pt2, int n);	//加密函数
void decrypt(char* pt, int* pt2, int n);	//解密函数
char* s_gets(char* st, int n);				//获取输入
int main()
{
	char input[WIDTH] = { " " };
	char num[WIDTH] = { 0 };

	for (int i = 0; i < WIDTH - 1; i++)		//随机数组，供加密解密使用
	{
		num[i] = (int)rand()%10;
	}

	printf("输入待加密内容:");
	s_gets(input, WIDTH - 1);
	encrypt(input,num,WIDTH-1);
	printf("加密后内容:%s\n", input);
	decrypt(input, num,WIDTH - 1);
	printf("解密后内容:%s\n", input);
	system("pause");
	return 0;
}
void encrypt(char* pt,int* pt2,int n)
{
	for (int i = 0; i < n; i++)
	{
		pt[i]+=pt2[i];
	}
}
void decrypt(char* pt, int* pt2, int n)
{
	for (int i = 0; i < n; i++)
	{
		pt[i] -=pt2[i];
	}
}
char* s_gets(char* st, int n)
{
	char* ret_val;
	int i = 0;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		while (st[i] != '\n'&&st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}