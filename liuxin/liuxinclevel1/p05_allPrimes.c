#include <time.h>
#include <stdio.h>
#include <string.h>
const int MAXN=10000005;
bool b[MAXN];
int n,tot,prime[MAXN];
void get_prime(int n);
int main(){
	scanf("%d",&n);
	int tmp=clock();
	get_prime(n);
	for (int i=1;i<=tot;++i) {
		printf("%d\n",prime[i]);
	}
	printf("time=%d ms\n",clock()-tmp);
	return 0;
}
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

/*
Ugly format
*/
