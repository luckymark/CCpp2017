//this program will print the solution of hanoi of n discs 
#include <stdio.h>
#include <string.h>
void dfs(int num,int a,int b,int c){
	if(num == 1){
		printf("%d -> %d\n", a,c);
		return;
	}
	dfs(num-1,a,c,b);
	dfs(1,a,b,c);
	dfs(num-1,b,a,c);
}
int main(){
	int n;
	scanf("%d",&n);
	dfs(n,1,2,3);
	return 0;
}
