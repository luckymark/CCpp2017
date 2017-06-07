// Goldbach.cpp : �������̨Ӧ�ó������ڵ㡣
//��100������֤��°ͺղ���

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
	int L = 0;																	//ѭ������
	int max = 100;																//����
	const int n = 25;															//2-100������һ����25��
	int Prime[n] = { 0 };														//��Prime���齫2-100�������ֱ�洢

	for (int i = 2; i <= max; i++)												//��2-100�����ֽ����ж�
	{
		if (check(i))
		{
			Prime[L] = i;
			++L;
		}
	}

	for (int i = 4; i <= 100; i += 2)											//���4-100�ڵ�ż��
	{
		for (int j = 0; j <= 24; j++)											//ѭ��2-100����������
		{
			for (int k = 0; k <= 24&&Prime[j]<(i/2)+1; ++k)						//ѭ��ʣ������
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

