#include <stdio.h>
void main()
{
	system("color 0a");
	while (1)
	{
		printf("0 1");
	}
}
//结果分析
//结果：屏幕无限制打印绿色字体的‘0’、‘1’
//system ("color 0a")使字体变绿
//while 语句条件表达式为1，代表真，无限执行循环“打印绿色字体0 1”
