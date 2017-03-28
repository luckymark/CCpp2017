#include <stdio.h>
int main(){
	int i,j,k;
	for (i=1;i<=9;++i)
		for (j=0;j<=9;++j)
			for (k=0;k<=9;++k) 
			if (i*i*i+j*j*j+k*k*k==i*100+j*10+k) {
				printf("%d%d%d\n",i,j,k);
			}
			
	return 0;
}

/*
Ugly format
*/
