#include<stdio.h>
#include<stdlib.h>
int IS(int);			//判断是否为素数

int main() {
	int x;
	
	printf("输入一个正整数，程序判断它是否为素数（q to quit）:");
	while (scanf_s("%d", &x))
	{
		if (x == 1 || x == 2)
		{
			puts("是素数");
		}
		else if (IS(x))
			puts("是素数.");
		else puts("不是素数.");
		printf("输入一个正整数，程序判断它是否为素数（q to quit）:");
	}
	system("pause");
	return 0;
}
int IS(int x)
{
	int i;
	int mark = 0;	//创建标记
	
	for (i = 2; i < x; i++)
	{
		if (x%i == 0)
		{
			mark = 1;	//若被整除，标记mark为1
			break;
		}
	}
	if (mark == 1)
		return 0;
	else return 1;
}
