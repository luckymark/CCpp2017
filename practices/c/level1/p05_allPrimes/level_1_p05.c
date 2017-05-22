#include<stdio.h>
#include<time.h>

int prime(int m)
{	
	for (int i=2;i*i<=m;i++){
		if(m%i==0)
		{return 0;}
	}
	return 1;
}

main()
{		
	double start,finish;
	start=clock();
	for(int i=2;i<=1000;i++){
		if(prime(i)>0){
		printf("%d\n",i);
		}
	}
	finish=clock();
	printf("\n");
	printf("%f",finish-start);
}
