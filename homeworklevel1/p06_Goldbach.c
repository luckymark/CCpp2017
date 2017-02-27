#include <stdio.h>
#include <string.h>
const int MAXN=10000005;
bool b[MAXN];
int n,tot,prime[MAXN];
void get_prime(int n) {
	memset(b,0,sizeof(b)); tot=0;
	for (int i=2;i<=n;++i) {
		if (!b[i]) prime[++tot]=i;
		for (int j=1;j<=tot&&prime[j]*i<=n;++j) {
			b[prime[j]*i]=1;
			if (i%prime[j]==0) break;
		}
	}
}
int main(){
	get_prime(100);
	int i,j,k;
	for (i=4;i<=100;i+=2) {
		for (j=1;j<=tot;++j) {
			for (k=1;k<=tot;++k) if (prime[j]+prime[k]==i) break;
			if (prime[j]+prime[k]==i) break;
		}
		printf("%d=%d+%d\n",i,prime[j],prime[k]);
	}
	return 0;
}
