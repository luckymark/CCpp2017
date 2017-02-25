//为什么不是2到100 
/*#include<stdio.h>
int main()
{
	for(int a=2;a<100;a++)
	{
		printf("%d\t",a);
	}
	return 0;
 }*/
 #include<stdio.h>
int main()
{

	for(int a=2;a<100;a++)
	{
		if(a%2==0)
		{
		printf("%d\t",a);
		}
		
	}
	return 0;	
 } 
