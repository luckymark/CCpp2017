#include<stdio.h>
int main()
{
	int num[10];
	int a;
	for(int i=0;i<=9;i++){
		num[i]=0;
	}
	for(int i=0;i<=4;i++){
		scanf("%d",&a);
		num[a]++;
	}
	for(int i=0;i<=9;i++){
		if(num[i]==0){
			printf("%d\n",i); 
		}
	}
	return 0;
}
