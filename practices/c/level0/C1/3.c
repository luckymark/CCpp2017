#include <stdio.h>
int main(){
		int n; 
		scanf(" %d",&n);
		printf("%s\n",( n % 4 == 0 && n % 100 != 0) || (n % 400 == 0) ? "YES" : "NO");
		return 0;
}
///算法来自百度
