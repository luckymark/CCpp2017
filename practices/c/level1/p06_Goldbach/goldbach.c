#include<stdio.h>//֤������2��ż������������������ӵõ� 
#include<stdlib.h>
int n=0;
int m_prime[100];
void prime();//�ҳ�100���ڵ����� 
int main()
{
	int i,j,k,l=0,p=0;
	prime();
	for(i=4;i<101;i+=2,p=0)
	{
		for(j=0;j<n;j++)
		for(k=0;k<n;k++)
		{
			if(i==m_prime[j]+m_prime[k])
			{
				p=1;
				printf("%d=%d+%d\n",i,m_prime[j],m_prime[k]);
				l++;
				break;
			}
			if(p==1)break;
		}
	}
	if(l==49)printf("right");
}
void prime()
{
	int i,j,k=0;
	for(i=2;i<101;i++,k=0)
	{
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			{
				k=1;
				break;
			}
		}
		if(k==0)
		{
			printf("%d ",i); 
			m_prime[n]=i;
			n++; 
		}
	}
}
