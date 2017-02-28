#include<stdio.h> 
#include<math.h> 
int checkprime(int m)
{
	int k;int i;
	k=sqrt(m);
	for (i=2;i<=k;i++)
		if (m%i==0) break;
		if (i>k) return 1;
		else return 0;
}

int main()
{
	int a;int prime[100];int b;int c=0;
	
	for(int i=2;i<=100;i++){
		b=checkprime(i);
		if(b==1){
			prime[c]=i;
			c++;
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
