#include<stdio.h>
int is_prime(int n);
int main(void)
{
	int n;
	scanf("%d",&n);
	if(is_prime(n))
	{
		printf("������\n");
	}
	else
	{
		printf("��������\n");
	}
	
	return 0;
	 
}
int is_prime(int n)
{
	int i;
	for(i=2;i<=n-1;i++)
	{
		if(n%i==0)
		{
			return 0;
		}
	}
	return 1;
}
