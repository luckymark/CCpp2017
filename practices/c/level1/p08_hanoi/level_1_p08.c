#include<stdio.h>
void hanoi(int n,char a,char b,char c){
	if(n==1){
		printf("move plate %d from column %c to column %c\n",n,a,c);
	} 
	else{
		hanoi(n-1,a,c,b);
		printf("move plate %d from column %c to column %c\n",n,a,c);
		hanoi(n-1,b,a,c);
	}
}

main(){
	int n;
	scanf("%d",&n);
	hanoi(n,'A','B','C');
}
