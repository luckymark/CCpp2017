//1742�꣬�¹���ѧ�Ҹ�°ͺ������ÿһ����С��6��ż����������������֮�ͣ�ÿһ����С��9��������������������֮�͡�
#include<stdio.h>
int i,s;
int odd(int a)//aΪ���������1��aΪż�������0 
{
	if(a%2==0)return 0;
	else return 1;
}
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
	int j,l;
	int k=0;
	int sus[100];
	for(j=2;j<100;j++)//��100����������sus�� 
	{
		if(sushu(j))//���j�����������sus�� 
		{
			sus[k]=j;
			k++;
		} 
	}
	k--;
	for(s=0;s<=k;s++)       
    printf("��%d������,ֵ%d,��%d\n",s+1,sus[s],k+1);//����һ��������ȷ��
	int m,n,b;
    for(l=5;l<=100;l++)//��ʼ���� 
	{
		if(odd(l))
		{
			if(l>8)//��С��9������ 
			{
				for(m=0;m<(k+1);m++)//��һ���� 
				{
					for(n=m;n<(k+1);n++)//�ڶ����� 
					{
						for(b=n;b<(k+1);b++)//�������� 
						{
							if(l==(sus[m]+sus[n]+sus[b]))
							{
							printf("��Ϊ%d����ֵΪ%d��%d��%d\n",l,sus[m],sus[n],sus[b]);
							goto FUCK;
						    }
						}
					}
				}
				printf("��°ͺղ��벻����\n");
				system("pause");
				return 0; 
			}
		}
		else//��С��6��ż�� 
		{
			for(m=1;m<(k+1);m++)//��һ������ 
			{
				for(n=1;n<(k+1);n++)//�ڶ������� 
				{
					if(l==(sus[m]+sus[n]))
					{
					printf("��Ϊ%d����ֵΪ%d��%d\n",l,sus[m],sus[n]);	
					goto FUCK;
				    }
				}
			}
			printf("��°ͺղ��벻����\n");
			system("pause");
			return 0; 
		}
	FUCK:;
	} 
	printf("��°ͺղ���С��100ʱ����\n");
	system("pause");
	return 0;
}
