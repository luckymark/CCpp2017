#include <stdio.h>
int main(void)
{
	int num;
	int i,j;
	
	printf("����һ����������"); 
	while((scanf("%d",&num)==1))
	{
		for(i=2,j=1;(i*i)<num;i++)
		{
			if(num%i==0)
			{
				printf("%d��������.\n",num);
				j=0; 
				break;
		    }
		}
		if(j==1)
			printf("%d������",num);
	}
	return 0;
 } 
