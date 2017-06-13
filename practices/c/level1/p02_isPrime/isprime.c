# include<stdio.h>

int main()
{
	int i,x = 0;
	int infox=-1;
	scanf("%d",&x);
	
	for( i=2;i<x;i++){
		if(x%i==0){
			infox++;
		}
	}
	
	if(infox==-1){
		printf("是素数\n");
	}
	else {
		printf("不是素数\n");
	}
	
	return 0;
}
