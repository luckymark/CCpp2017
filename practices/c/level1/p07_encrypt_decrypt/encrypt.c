#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main(void)
{
	char a;
	char ch;
	printf("请选择：A.加密 B.解密\n");
	scanf("%c",&a);
	fflush(stdin);
	switch(a)
	{
		case 'A':{
			printf("请输入源字符串\n");
			while(ch=getchar())
			{
				putchar(ch+3);
			}
			break;
		}
		case 'B':{
			printf("请输入源字符串\n");
			while(ch=getchar())
			{
				putchar(ch-3);
			}
			break;
		}
		default:printf("输入错误"); 
	}

}
