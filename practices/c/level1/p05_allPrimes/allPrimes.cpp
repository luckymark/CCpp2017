#include "stdafx.h"
#include<stdio.h>
#include<time.h>

int main()
{
	double begin;
	double end;
	int max = 1000;
	int judge=1;
	int x;
	
	begin = clock();							//��¼��ʼʱ��

	for (int i = 2; i <= max; i++)				//����2-1000������
	{
		for (int j = 2; j < i; j++)				//����Щ���ֽ����ж�
		{
			if (i%j == 0)						//���ȡ����Ϊ0��������
			{
				judge = 0;
				break;
			}
			judge = 1;							//�����������
		}
		if(judge==1)							//���������
		{
			x = i;								//��ʱ��i��ֵ��ֵ��x���������
			printf("%d\n", x);
		}
	}							
	end = clock();							//��¼����ʱ��
	printf("%lf\n", (end - begin)/1000);	//���������ʱ��

	getchar();								//��ͣ
	return 0;
}
	


