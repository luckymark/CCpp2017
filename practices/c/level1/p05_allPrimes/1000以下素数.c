#include<stdio.h>
int i;
int sushu(int a)//aΪ���������1��a�����������0 
{
	for(i=2;i<a;i++)//��������a����1��������1��������bug 
	{
		if(a%i==0)return 0;
	} 
	return 1;
}
int main(void)
{
	int j;
	int k=0;
	int sus[1000];
	for(j=2;j<1000;j++)//��100����������sus�� 
	{
		if(sushu(j))//���j�����������sus�� 
		{
			sus[k]=j;
			k++;
		} 
	}
	k--;
	int s;
	for(s=0;s<=k;s++)       
    printf("��%d������,ֵ%d,��%d\n",s+1,sus[s],k+1);//����һ��������ȷ��
    return 0;
}
