#include <stdio.h>

int main()
{
	int year;
	
	printf("请输入年份： ");
	scanf("%d",&year);
	
	if((year%4==0&&year%100!=0)||year%400==0)
	{
		printf("该年为闰年");
	} 
	else
	{
		printf("该年不是闰年");
	}
	
	return 0;
}
