#include <stdio.h>

int main()
{
	long long n;
	printf("请输入任意正整数n,以判断n是否为素数\nn = ");
	scanf("%ld", &n);
	if(n==1){
		printf("1不是素数\n"); 
		return 0;
	}
	for(long long i=2; i*i<=n; i++)
	{
		if(n%i==0){
			printf("%d不是素数\n", n);
			return 0;
		}
	}
	printf("%d是素数\n", n);
	return 0;
 } 
