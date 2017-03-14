// encrypt_decrypt2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>

void change(char *p)
{
	for (; *p != '\0'; *p++)
	{
		if (*p == 'x')
		{
			*p = 'a';
		}
		else if (*p == 'y')
		{
			*p = 'b';
		}
		else if (*p == 'z')
		{
			*p = 'c';
		}
		else if (*p == 'X')
		{
			*p = 'A';
		}
		else if (*p == 'Y')
		{
			*p = 'B';
		}
		else if (*p == 'Z')
		{
			*p = 'C';
		}
		else if (*p == '7')
		{
			*p = '0';
		}
		else if (*p == '8')
		{
			*p = '1';
		}
		else if (*p == '9')
		{
			*p = '2';
		}
		else
		{
			*p = *p + 3;
		}
	}
}

int main()
{
	char encrypt[1000];
	char* ps = encrypt;
	gets_s(encrypt);

	printf("请输入需要加密的内容：");
	while (*ps)
	{
		putchar(*ps);
		ps++;
	}
	printf("\n");

	change(encrypt);
	printf("您得到的加密后内容为：%s\n",encrypt);

	getchar();
    return 0;
}

