#include <stdio.h>

int main()
{
	int num=1;
	
	for(num;num<=100;num++)
	{
		if(num%7==0||num%10==7)
		{
			printf("%d\t",num);
		}
	}
	return 0;
}
