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
	
	begin = clock();							//记录开始时间

	for (int i = 2; i <= max; i++)				//输入2-1000的数字
	{
		for (int j = 2; j < i; j++)				//对这些数字进行判断
		{
			if (i%j == 0)						//如果取余结果为0则不是素数
			{
				judge = 0;
				break;
			}
			judge = 1;							//否则就是素数
		}
		if(judge==1)							//如果是素数
		{
			x = i;								//此时将i的值赋值给x并将其输出
			printf("%d\n", x);
		}
	}							
	end = clock();							//记录结束时间
	printf("%lf\n", (end - begin)/1000);	//输出运行总时间

	getchar();								//暂停
	return 0;
}
	


