#include<stdio.h>

void main()
{
	int a[5];
	printf("����5����");
	int i,b;
	for(i=1;i<=5;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("û�г��ֵ���Ϊ");
	for(b=0;b<=9;b++)
	{
		if(b!=a[1]&&b!=a[2]&&b!=a[3]&&b!=a[4]&&b!=a[5])
	    {
	    	printf("%d",a[i]);
		}
	}
}
