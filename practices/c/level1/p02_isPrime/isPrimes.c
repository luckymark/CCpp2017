#include<stdio.h>
int main()
{
	int a,n=0;
	scanf("%d",&a);
	for(int i=2;i<a;i++){
		if(a%i==0){
			n=1; 
		}
	}
	if(n==0){
		printf("yes");
	}else{
		printf("no");
	}
	return 0;
 } 
