#include <stdio.h>
void move(char a,char b,char c,int n);
int main()
{
	int n =4;
	char a='a' , b='b' , c='c';
	move(a,b,c,n);
}

void move(char a,char b,char c,int n)   //�ú�����n����Ƭ��a���Ƶ�c�� 
{
	if(n==1)
	{
		printf("%c-->%c\n",a,c);   //���ֻ��һ����Ƭֱ�����a-->c 
	}
	else
	{
		move(a,c,b,n-1);      			//���Ȱ������n-1����Ƭ�Ƶ�b�� 
		printf("%c-->%c\n",a,c);     //�ٰѵ�n���Ƶ�c�� 
		move(b,a,c,n-1);			//����ٰ���b����n-1���Ƶ�c�� 
	}
}
