#include <stdio.h>

int main()
{
	long long n;
	printf("����������������n,���ж�n�Ƿ�Ϊ����\nn = ");
	scanf("%ld", &n);
	if(n==1){
		printf("1��������\n"); 
		return 0;
	}
	for(long long i=2; i*i<=n; i++)
	{
		if(n%i==0){
			printf("%d��������\n", n);
			return 0;
		}
	}
	printf("%d������\n", n);
	return 0;
 } 
