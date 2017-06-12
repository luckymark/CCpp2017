#include<stdio.h>
int main()

{
	int n;
	int isPrime=1; 
	scanf("%d",&n);
	for(int i=2;i<n;i++)
	{
		if (n%i==0){
		printf("%d不是素数",n);
		isPrime=0;
		break;
		} 
	}	
	if(isPrime==1){
		printf("%d是素数",n);
	}
	return 0;
} 
