#include<stdio.h> 

int checkprime(int m)
{	
	for (int i=2;i*i<=m;i++){
		if(m%i==0)
		{return 0;}
	}
	return 1;
}

int main()
{
	int a;int prime[100];int control_1=0;
	
	for(int i=2;i<=100;i++){
		if(checkprime(i)==1){
			prime[control_1]=i;
			control_1++;
		}
		
	}
	for(int i=2;i<=50;i++){
		for(int j=0;j<=24;j++){
				a=2*i-prime[j];
				if(checkprime(a)==1){
					printf("%d=%d+%d\n",2*i,a,prime[j]);break;
				}	
		}
	}
}
