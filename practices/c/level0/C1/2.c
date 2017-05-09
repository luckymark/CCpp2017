#include <stdio.h>
int main(){
	int n; 
	scanf(" %d", &n);
	printf("%s\n",(n % 13 == 0 ? "YES" : "NO"));
	return 0;
}
