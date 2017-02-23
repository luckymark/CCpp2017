#include<stdio.h>
#include<stdlib.h> 
int main(void)//a为素数则输出1，a非素数则输出0 
{
	int i,a;
	printf("请输入数据");
	scanf("%d",&a);
	if(a>1)
	{
	for(i=2;i<a;i++)//加入限制a大于1否则会出现1是素数的bug 
	{
		if(a%i==0)
		{
			printf("不是素数"); 
		    return 0;
		} 
	}
	printf("是素数"); 
	return 0;
    }
    else
    {
    	printf("请输入大于1的整数！"); 
	}
} 
