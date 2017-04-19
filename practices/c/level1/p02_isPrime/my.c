#include <string.h>
#include <stdio.h>
int main(){
	int n; 
	scanf("%d",&n);
	int flag = 1;
	for(int i = 2; i*i <= n; i++)
		if(n % i == 0){
			flag = 0;
			break;
		}
	printf("%s\n",(flag == 1 ? "YES" : "NO"));
	return 0;
}
