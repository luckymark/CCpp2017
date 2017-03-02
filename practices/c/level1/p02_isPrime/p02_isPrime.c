#include <stdio.h>
int main(void)
{
	int num;
	int i,j;
	
	printf("输入一个正整数："); 
	while((scanf("%d",&num)==1))
	{
		for(i=2,j=1;(i*i)<num;i++)
		{
			if(num%i==0)
			{
				printf("%d不是素数.\n",num);
				j=0; 
				break;
		    }
		}
		if(j==1)
			printf("%d是素数",num);
	}
	return 0;
 } 
