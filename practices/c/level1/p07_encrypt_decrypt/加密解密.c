#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char coding(char *s)//���� 
{
	int i;
	int k=strlen(s);
	for(i=0;i<k;i++)
	{
		s[i]=s[i]+3;
	}
	return 0;
}
char uncoding(char *s)//���� 
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
	printf("������Դ�ַ���\n");
	gets(s);
	printf("��ѡ��A.���� B.����\n");
	scanf("%c",&a);
	switch(a)
	{
		case 'A':{
			coding(s);
            printf("���ܽ����%s",s);
			break;
		}
		case 'B':{
			uncoding(s);
			printf("���ܽ����%s",s);
			break;
		}
		default:printf("�������"); 
	}

}
