//1742年，德国数学家哥德巴赫提出：每一个不小于6的偶数都是两个奇素数之和；每一个不小于9的奇数都是三个奇素数之和。
#include<stdio.h>
int i,s;
int odd(int a)//a为奇数则输出1，a为偶数则输出0 
{
	if(a%2==0)return 0;
	else return 1;
}
int sushu(int a)//a为素数则输出1，a非素数则输出0 
{
	for(i=2;i<a;i++)//加入限制a大于1否则会出现1是素数的bug 
	{
		if(a%i==0)return 0;
	} 
	return 1;
} 
int main(void)
{
	int j,l;
	int k=0;
	int sus[100];
	for(j=2;j<100;j++)//将100下素数放入sus中 
	{
		if(sushu(j))//如果j是素数则放入sus中 
		{
			sus[k]=j;
			k++;
		} 
	}
	k--;
	for(s=0;s<=k;s++)       
    printf("第%d个素数,值%d,共%d\n",s+1,sus[s],k+1);//检验一下素数正确性
	int m,n,b;
    for(l=5;l<=100;l++)//开始计算 
	{
		if(odd(l))
		{
			if(l>8)//不小于9的奇数 
			{
				for(m=0;m<(k+1);m++)//第一个数 
				{
					for(n=m;n<(k+1);n++)//第二个数 
					{
						for(b=n;b<(k+1);b++)//第三个数 
						{
							if(l==(sus[m]+sus[n]+sus[b]))
							{
							printf("数为%d，三值为%d、%d、%d\n",l,sus[m],sus[n],sus[b]);
							goto FUCK;
						    }
						}
					}
				}
				printf("哥德巴赫猜想不成立\n");
				system("pause");
				return 0; 
			}
		}
		else//不小于6的偶数 
		{
			for(m=1;m<(k+1);m++)//第一个素数 
			{
				for(n=1;n<(k+1);n++)//第二个素数 
				{
					if(l==(sus[m]+sus[n]))
					{
					printf("数为%d，二值为%d、%d\n",l,sus[m],sus[n]);	
					goto FUCK;
				    }
				}
			}
			printf("哥德巴赫猜想不成立\n");
			system("pause");
			return 0; 
		}
	FUCK:;
	} 
	printf("哥德巴赫猜想小于100时成立\n");
	system("pause");
	return 0;
}
