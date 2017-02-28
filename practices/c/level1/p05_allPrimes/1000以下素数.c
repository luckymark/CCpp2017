#include<stdio.h>
int sushu(int a);//a为素数则输出1，a非素数则输出0 
int main(void)
{
	int k=0;
	int sus[100];
	for(int j=2;j<1000;j++)//将100下素数放入sus中 
	{
		if(sushu(j))//如果j是素数则放入sus中 
		{
			sus[k]=j;
			k++;
		} 
	}
	for(int s=0;s<k;s++)       
    printf("第%d个素数,值%d,共%d\n",s+1,sus[s],k);输出素数 
    return 0; 
}
int sushu(int a)
{
	for(int i=2;i<a;i++)//加入限制a大于1否则会出现1是素数的bug 
	{
		if(a%i==0)return 0;
	} 
	return 1;
}
