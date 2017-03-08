#include<stdio.h>
#include<math.h>
#include<time.h>

int main()
{
	for(int n=2;n<=1000;n++){
	int count=1;
		for(int i=2;i<=sqrt(n);i++){
			if(n%i==0){
				count=0;
			}
		}
		if(count==1){
			printf("%d\t",n);
		}
	}
	printf("\ntime:%d",clock());
	return 0;
}
