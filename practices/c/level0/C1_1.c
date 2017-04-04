#include <stdio.h>

int main()
{
	int a,b;
	printf("请输入一个a的值： "); 
	scanf("%d",&a);
	b=a%2;
	
	if (a>0)
	{
		printf("a为正数"); 
	}
	else if (a<0)
	{
		printf("a为负数"); 
	}
	else
	{
		printf("a为0");
	}
	
        printf("\n");
	
	if (b==0)
        {
    	printf("a为偶数");
	}
	else
	{
        printf("a为奇数");
        }
	
        return 0;
}
