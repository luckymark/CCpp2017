#include <stdio.h>
int main()
{
	int a;
	printf("������ݣ�");
	scanf("%d",&a);
	if(a%400==0||a%100!=0&&a%4==0)
	{
		printf("aΪ����");
	}
	else
	{
		printf("a��Ϊ����");
	}
}
