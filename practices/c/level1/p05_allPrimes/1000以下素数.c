#include<stdio.h>
int sushu(int a);//aΪ���������1��a�����������0 
int main(void)
{
	int k=0;
	int sus[100];
	for(int j=2;j<1000;j++)//��100����������sus�� 
	{
		if(sushu(j))//���j�����������sus�� 
		{
			sus[k]=j;
			k++;
		} 
	}
	for(int s=0;s<k;s++)       
    printf("��%d������,ֵ%d,��%d\n",s+1,sus[s],k);������� 
    return 0; 
}
int sushu(int a)
{
	for(int i=2;i<a;i++)//��������a����1��������1��������bug 
	{
		if(a%i==0)return 0;
	} 
	return 1;
}
