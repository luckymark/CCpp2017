#include <stdio.h>
int main(void)
{
	int num;
	
	printf("����һ���������ж����Ƿ�Ϊ13�ı���\n"); 
	while(scanf("%d",&num)){
		if(num%13==0){
		   printf("%d��13�ı���\n",num);
		} 
		else{ 
		   printf("%d����13�ı���\n",num);
		} 
	}
	return 0;
 } 
