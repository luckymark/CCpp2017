#include <math.h>
#include <stdio.h>
int main(){
	int n,i,j;
	scanf("%d",&n);
	for (i=2,j=1;i<=trunc(sqrt(n));++i)
	if (n%i==0) {
		j=0; break;
	}
	if (j&&n!=1) {
		printf("YES\n"); 
	}else{
		printf("NO\n");
	}
	return 0;
}

/*
Ugly format
*/
