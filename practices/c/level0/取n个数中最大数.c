#include<stdio.h>

int main(void)
{
	int m,n,l,s,i;
	printf("您想输入几个数字:");
	scanf("%d",&n);
	printf("please input %d numbers:\n",n);

	for(i=0;i<n ;++i){
	    scanf("%d",&m);
	    if(m>l){
	       s=m;
	       l=s;}
	}

	printf("%d 是这些数字中最大的",s);


	return 0;

}

