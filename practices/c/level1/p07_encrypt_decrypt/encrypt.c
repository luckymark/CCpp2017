#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main(void)
{
	char a;
	char ch;
	printf("��ѡ��A.���� B.����\n");
	scanf("%c",&a);
	fflush(stdin);
	switch(a)
	{
		case 'A':{
			printf("������Դ�ַ���\n");
			while(ch=getchar())
			{
				putchar(ch+3);
			}
			break;
		}
		case 'B':{
			printf("������Դ�ַ���\n");
			while(ch=getchar())
			{
				putchar(ch-3);
			}
			break;
		}
		default:printf("�������"); 
	}

}
