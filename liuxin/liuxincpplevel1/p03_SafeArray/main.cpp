#include <cstdio>
#include <iostream>
#include "SafeArray.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,m,i,j,k,l;
	scanf("%d",&n);
	SafeArray A(n+1);
	for (i=1;i<=n;++i) {
		scanf("%d",&A[i]);
	}
	scanf("%d",&m);
	for (i=0;i<m;++i) {
		scanf("%d%d",&j,&k);
		A[j]=k;
		for (l=1;l<=n;++l) {
			printf("%d ",A[l]);
		}
		puts("");
	}
	return 0;
}
