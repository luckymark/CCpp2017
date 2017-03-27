#include <stdio.h>

const int n=3;

int sum(int a[n])
{
  int m;
	int i;
	for(m=0,i=0;i<n;i++)
	{
		m+=a[i];
	}
	return m;
}

int main()
{
	int c;
	int a[n]={3,2,3};
	c=sum(a);
	printf("%d",c);
	
	return 0;
}
