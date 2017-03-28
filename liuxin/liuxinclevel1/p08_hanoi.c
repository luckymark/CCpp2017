#include <stdio.h>
void work(int n,int x,int y,int z);
int main(){
	int n;
	scanf("%d",&n);
	work(n,0,1,2);
	return 0;
}
void work(int n,int x,int y,int z){
	if (n==0) return;
	work(n-1,x,z,y);
	printf("%c --> %c\n",x+'a',z+'a');
	work(n-1,y,x,z);
}
//Nice!