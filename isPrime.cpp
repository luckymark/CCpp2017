#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
bool is_prime(ll x)
{
	if(x==1)
	  return 0;
	for(ll i=2;i*i<=x;++i)
	  if(x%i==0)
	    return 0;
	return 1;
}
ll n;
int main()
{
	cin>>n;
	puts(is_prime(n) ? "YES" : "NO");
	return 0;
}
