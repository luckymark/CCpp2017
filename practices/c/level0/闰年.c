#include <stdio.h>
int main()
{
	int a;
	printf("输入年份：");
	scanf("%d",&a);
	if(a%400==0||a%100!=0&&a%4==0)
	printf("a为闰年");
	else
	printf("a不为闰年");
}
