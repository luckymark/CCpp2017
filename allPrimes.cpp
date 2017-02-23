#include<cstdio>
#include<ctime>
using namespace std;
#define MAXP 1001
bool isNotPrime[MAXP+10];
int num_prime,prime[MAXP+10];
void shai()
{
    for(int i=2;i<MAXP;i++)
      {
        if(!isNotPrime[i])
          prime[num_prime++]=i;
        for(int j=0;j<num_prime && i*prime[j]<MAXP;++j)
          {
            isNotPrime[i*prime[j]]=1;
            if(!(i%prime[j]))
                break;
          }
      }
    for(int i=0;i<num_prime;++i)
      printf("%d\n",prime[i]);
}
int main()
{
	int t=clock();
	shai();
	printf("%d\n",clock()-t);
	return 0;
}
