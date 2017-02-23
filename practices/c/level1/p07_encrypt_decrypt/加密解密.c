#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char coding(char *s)//加密 
{
	int i;
	int k=strlen(s);
	for(i=0;i<k;i++)
	{
		s[i]=s[i]+3;
	}
	return 0;
}
char uncoding(char *s)//解密 
{
	int i;
	int k=strlen(s);
	for(i=0;i<k;i++)
	{
		s[i]=s[i]-3;
	}
	return 0;
}
int main(void)
{
	char s[100];
	int i;
	char a;
	printf("请输入源字符串\n");
	gets(s);
	printf("请选择：A.加密 B.解密\n");
	scanf("%c",&a);
	switch(a)
	{
		case 'A':{
			coding(s);
            printf("加密结果是%s",s);
			break;
		}
		case 'B':{
			uncoding(s);
			printf("解密结果是%s",s);
			break;
		}
		default:printf("输入错误"); 
	}

}
