#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int isPrinme(int n);
int IS(int);
int main()
{
	clock_t t1, t2;
	t1 = clock();
	
	for(int i=2;i<=1000;i++)
	{
		if (isPrime(i))
		{
			printf("%5d", i);
		}
	}
	t2 = clock();
	printf("打印时间:%f秒",(double)(t2-t1)/CLOCKS_PER_SEC);
	
	system("pause");
	return 0;
}
int isPrime(int n) 
{
	int mark = 0;
	
	for (int i = 2; i < n; i++)
	{
		if (n%i == 0)	//用mark标记a已被整除
		{
			mark = 1;
			break;
		}

	}
	if (mark == 1)		//检查标记
		return 0;
	else return 1;
}
