#include<cstdio>
#include<cstdlib>
#include <cmath>
#include <iostream>


//wait,哥德巴赫猜想是啥啊？每个不小于6的偶数都可以表示为两个奇素数之和；本程序只解决了猜想1 
 
using namespace std;

int is_PrimeNumber(int n)
{
		if(n<2) return 0;
		if(n==2) return 1;
		for(int i=2;i<sqrt(n+1);i++)
		{
			
			if(n%i == 0) 
			{
				return 0;
			}
			if(i>2)
			{
				if(i%2) continue;
			}
			 
		}
		return 1;	

}
void find_OddPrime(int n,int *TempForOddPrime)
{

	for(int i=3;i<n;i+=2)
	{
		int j=0;
		if(is_PrimeNumber(i)) 
		{
			int TempForAnotherOddPrime=n-i;
			if(is_PrimeNumber(TempForAnotherOddPrime))
			{
				TempForOddPrime[j++]=i;
				TempForOddPrime[j]=TempForAnotherOddPrime;
			}
		}
	} 

}


int main()
{
	int n;
	int TempForOddPrime[3];
	if(scanf("%d",&n) == 1)
	{
		if( n<6 || n%2 )
		{
			printf("error input!");
			exit(1);
		} 
		find_OddPrime(n,TempForOddPrime);
		cout<<n<<"="<<TempForOddPrime[0]<<"+"<<TempForOddPrime[1]<<endl;
	}

	 
	return 0;
}
 