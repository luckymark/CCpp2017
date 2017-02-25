#include <stdio.h>
#include <math.h>
bool IsPrime(int n);

int main()
{
	int primes[24]={3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97}; //100���ڵ��������� 
	for(int i=4;i<101;i+=2)
	{
		for(int j=0;j<24;j++)
		{
			if(i-primes[j]<=0)
			{
				printf("%d flase",i);  //������ʱ���false 
			}	
			else if(IsPrime(i-primes[j]))
			{
				printf("%d=%d+%d\n",i,primes[j],i-primes[j]);
				break;
			}			
		}
		
	}	
}

bool IsPrime(int n)  //�ж������ĺ��� 
{
	for(int i=2;i<=sqrt(n);i++)
		{
			if(n%i==0)
			{				
				return false;
			}
		}
	return true;
} 
