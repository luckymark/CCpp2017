#include<stdio.h>
#include<stdlib.h> 
int main(void)//aΪ���������1��a�����������0 
{
	int i,a;
	printf("����������");
	scanf("%d",&a);
	if(a>1)
	{
	for(i=2;i<a;i++)//��������a����1��������1��������bug 
	{
		if(a%i==0)
		{
			printf("��������"); 
		    return 0;
		} 
	}
	printf("������"); 
	return 0;
    }
    else
    {
    	printf("���������1��������"); 
	}
} 
