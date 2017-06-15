#include<stdio.h>
int ming(int n);
int main()
{
	int n=100,i,j,k;
	while(1)
	{
		i=n/100;
		j=(n-i*100)/10;
		k=n-i*100-j*10;
		if(n==ming(i)+ming(j)+ming(k))printf("%d ",n);
		if((n++)==999)break;
	}
} 
int ming(int n)
{
	int p=1; 
	for(int i=0;i<3;i++)p*=n;
	return p;
}
