#include<cstdio>
#include<ctime>
using namespace std;
bool is_prime(int x)
{
	if(x==1 || x==0) return 0;
	for(int i=2;i*i<=x;++i)
	  if(x%i==0)
	    return 0;
	return 1;
}
int main()
{
	for(int i=4;i<=100;i+=2)
	  {
	  	for(int j=1;j<=i;++j)
		  if(is_prime(j) && is_prime(i-j))
	  	    {
	  	      printf("%d = %d + %d\n",i,j,i-j);
	  	      goto OUT;
	  	    }
	  	OUT:;
	  }
	return 0;
}
