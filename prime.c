#include <stdio.h>
int pd(int n)
{
	if(n==1||n==2)
	{
		return 1;
	}
	for(int i=2;i<=n/2;i++)
	{
		if(n%i==0)
		{
			return 0;
		}
	}
	return 0;
 } 
 int main()
 {
 	printf("Please Input a Number");
 	int n;
 	scanf("%s",&n);
 	if(pd(n)==0)
 	{
 		print("Not Prime");
	 }
	 else
	 {
	 	print("Prime");
	 }
	 return 0;
 }
