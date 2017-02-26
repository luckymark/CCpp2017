#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int loadPrime(int* a);
int isPrime(int x);
int main()
{
	int prime[100] = {0};
	int sum;
	sum=loadPrime(prime);
	for (int a = 4; a <= 100;a+=2 )
	{
		for (int i = 0; i < sum; i++)
		{
			for (int j = 0; j < sum; j++)
			{
				if (a == prime[i] + prime[j])		//遍历两个100以内的素数组合之和，与a作比较
				{
					printf("%d满足哥德巴赫猜想\n",a);
					goto b;							//跳出遍历循环
				}
			}
		}
	
	b: ;
	}
	system("pause");
	return 0;
}
int isPrime(int x)
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
	}if (mark == 1)
		return 0;
	else return 1;
}
int loadPrime(int* a)
{	
	int x = 0;		
	for (int i = 1; i < 100; i++)
	{
		if (isPrime(i))
		{
			a[x] = i;	//把素数赋值给数组
			x++;
		}
	}
	return x;		//返回100以内的素数个数
}