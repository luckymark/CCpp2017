#include <cmath>
#include <cstdio>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	for (int i=2;i<=trunc(sqrt(n));i++)
		if (n%i==0)
			{
				puts("It is not a prime.");
				return 0;
			}
	puts("It is a prime.");
	return 0;
}