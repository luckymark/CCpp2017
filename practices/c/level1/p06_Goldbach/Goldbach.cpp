// Goldbach.cpp : 定义控制台应用程序的入口点。
//在100以内验证哥德巴赫猜想

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

bool check(int a)
{
	if (a == 2)
	{
		return true;
	}
	for (int i = 2; i < a; ++i)
	{
		if (a%i == 0)
		{
			return false;
		}
	}
	return true;
}

int main(void) 
{
	int L = 0;																	//循环变量
	int max = 100;																//上限
	const int n = 25;															//2-100的素数一共有25个
	int Prime[n] = { 0 };														//用Prime数组将2-100的素数分别存储

	for (int i = 2; i <= max; i++)												//对2-100的数字进行判断
	{
		if (check(i))
		{
			Prime[L] = i;
			++L;
		}
	}

	for (int i = 4; i <= 100; i += 2)											//输出4-100内的偶数
	{
		for (int j = 0; j <= 24; j++)											//循环2-100的所有素数
		{
			for (int k = 0; k <= 24&&Prime[j]<(i/2)+1; ++k)						//循环剩余素数
			{
				if (i - Prime[j] == Prime[k])
				{
					printf("%d=%d+%d\n", i, Prime[j], Prime[k]);
				}
			}

		}
	}

	getchar();
	return 0;
}

