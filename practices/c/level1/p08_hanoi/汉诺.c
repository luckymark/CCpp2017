#include<stdio.h>
#include<stdlib.h>
int hannuo(int n,char q,char w,char e)//״̬��ͬ  ״̬ת��  
{
	if(n==1)
	{
		printf("���������Ӵ�%c���Ƶ�%c��\n",q,e);
	}
	else
	{
		hannuo(n-1,q,e,w);
		hannuo(1,q,w,e);
		hannuo(n-1,w,q,e);
	}
	return 0;
}
int main(void)
{
	int n;
	printf("�����뺺ŵ���Ĳ���\n");
	scanf("%d",&n); 
	hannuo(n,'A','B','C');
	return 0;
}

