#include<stdio.h>

void hanoi(int n,char from,char mid,char aim);
int main(){
	int n;
	scanf("%d",&n);
	hanoi(n,'a','b','c');
	return 0;
}
void hanoi(int n,char from,char mid,char aim){
	if (n==1) {
		printf("%c -> %c\n",from,aim);
	}
	else {
		hanoi(n-1,from,aim,mid);
		printf("%c -> %c\n",from,aim);
		hanoi(n-1,mid,from,aim);
	}
}