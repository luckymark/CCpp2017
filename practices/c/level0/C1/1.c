#include <stdio.h>
#include <string.h>
char ans1[3][10] = {"正数","负数","0"};
char ans2[2][10] = {"奇数","偶数"};
char *ans[2];
int sgn(int n){
	if(n == 0) return 2;
	return n > 0 ? 0 : 1;
}
int main(){
	int n;
	scanf(" %d",&n);
	ans[0] = ans1[sgn(n)];
	ans[1] = n % 2 ? ans2[0] : ans2[1];
	printf("%s %s", ans[0], ans[1]);
	return 0;
}
