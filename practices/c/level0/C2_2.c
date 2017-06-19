#include <stdio.h>

int main()
{
	int num=1;
	
	for(num;num<=100;num++)
	{
		if(num%3==0&&num%5!=0)
		{
			printf("%d\t",num);
		}
	}
	return 0;
}
