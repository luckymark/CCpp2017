#include<stdio.h>
main()
{
	printf("三位数的水仙数为:\n");	
	for(int a=100;a<1000;a++)
	{ 
		int hun=a/100;
		int ten=a/10-hun*10;
		int one=a-hun*100-ten*10;
	
		if(a==hun*hun*hun+ten*ten*ten+one*one*one)
		{
			printf("%d\t",a);
		}
		
	}
	return 0;
}
