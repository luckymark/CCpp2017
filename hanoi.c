#include<stdio.h>

void hanoi(int n,char from,char via,char to);

int main(){
	int n;
	//input the num of the plates
	scanf("%d",&n);
	hanoi(n,'A','B','C');
	return 0;
}

void hanoi(int n,char from,char via,char to){
	if(n==1){
		printf("%c->%c\n",from,to);
		return;
	}
	hanoi(n-1,from,to,via);
	printf("%c->%c\n",from,to);
	hanoi(n-1,via,from,to);
}
