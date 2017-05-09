#include <cstdio>
#include "SafeArray.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int length;
	scanf("%d",&length);
	SafeArray safearray;
	safearray.sizeable(length);
	for (int i=0;i<length;i++){
		safearray[i]=i;
	}
	for (int i=0;i<length;i++){
		printf("%d ",safearray[i]);
	}
	printf("\n");
	printf("%d\n",safearray[length]);
	safearray[length]=10; 
	return 0;
}
