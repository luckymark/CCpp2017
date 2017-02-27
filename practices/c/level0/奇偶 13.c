#include<stdio.h>
main()
{
	int a;
	printf("输入a的值：");
	scanf("%d",&a);
	
	if(a>0)
	printf("a为正数");
	else if(a==0)
	printf("a为0");
	else 
	printf("a为负数");
	printf("\n");
	
	if(a%2==0)
	printf("a为偶数");
	else 
	printf("a为奇数"); 
	printf("\n");
	
	if(a%13==0)
	printf("a为13倍数");
	else
	printf("a不为13倍数");
}
