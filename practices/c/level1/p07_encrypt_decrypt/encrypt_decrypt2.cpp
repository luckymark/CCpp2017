// encrypt_decrypt2.cpp : �������̨Ӧ�ó������ڵ㡣
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

	printf("��������Ҫ���ܵ����ݣ�");
	while (*ps)
	{
		putchar(*ps);
		ps++;
	}
	printf("\n");

	change(encrypt);
	printf("���õ��ļ��ܺ�����Ϊ��%s\n",encrypt);

	getchar();
    return 0;
}

