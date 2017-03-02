#include <stdio.h>

int main()
{
	int i=1;
	printf(" \t1\t2\t3\t4\t5\t6\t7\t8\t9\n");
	
	for(i;i<10;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i,i,i*2,i*3,i*4,i*5,i*6,i*7,i*8,i*9);
	}
	return 0;
}
