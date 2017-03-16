#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void hanoi(int n,char from,char by,char to);
void move(from,to);
int main(int argc, char *argv[]) {
	int n;
	scanf("%d",&n);
	hanoi(n,'A','B','C');
	return 0;
}

void hanoi(int n,char from,char by,char to){
	if(n==1){
		move(from,to);
		return;
	}
	hanoi(n-1,from,to,by);
	move(from,to);
	hanoi(n-1,by,from,to);
}

void move(from,to){
	printf("%c->%c\n",from,to);
}
