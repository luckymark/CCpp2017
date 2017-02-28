#include<stdio.h>
#include<math.h>
int prime(int);
main()
{
	int i,j;
	for(i=2;i<=1000;i++){
		if(prime(i)>0)
		printf("%d\n",i);
	}
}

int prime(int m)
{
	int k;int i;
	k=sqrt(m);
	for (i=2;i<=k;i++)
		if (m%i==0) break;
		if (i>k) return m;
	else return 0;
}
