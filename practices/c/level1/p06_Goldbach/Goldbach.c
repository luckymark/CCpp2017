#include<stdio.h>
#include<math.h>
int is_prime(int n);
int _prime(int *P);
void Goldbach(int *P,int n);
int main(void)
{
	int prime[100];
	int max;
	max=_prime(prime);
    Goldbach(prime,max);
    
    return 0;
	
}
void Goldbach(int *P,int n)
{
	int even=4;
	int i,j;
	int B;
	while(even<=100)
	{
		B=0;
		for(i=0;i<n;i++)
		{
			for(j=i;j<n;j++)
			{
				if(even==P[i]+P[j])
				{
					printf("%3d=%3d+%3d\n",even,P[i],P[j]);
					even+=2;
					B=1;
					break;
				}
			}
			if(B==1)
			{
				break;
			} 
		}
	}
	printf("100以内的哥德巴赫猜想成立!\n");
	system("pause"); 
}
int _prime(int *P)
{
	int i,j=0;
	for(i=2;i<=100;i++)
	{
		if(is_prime(i))
		{
			P[j]=i;
			j++;
		}
	}
	return j;
}
int is_prime(int n)
{
	int i;
	for(i=2;i<=pow(n,0.5);i++)
	{
		if(n%i==0)
		{
			return 0;
		}
	}
	return 1;
}
