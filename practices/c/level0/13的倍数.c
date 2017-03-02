#include <stdio.h>
int main(void)
{
	int num;
	printf("输入一个整数以判断它是否为13的倍数\n"); 
	while(scanf("%d",&num)){
		if(num%13==0)
		printf("%d是13的倍数\n",num);
		else 
		printf("%d不是13的倍数\n",num); 
	}
	return 0;
 } 
