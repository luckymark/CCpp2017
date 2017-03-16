#include <stdio.h>

void printMove(int x, char A, char B);
void hanoi(int x, char A, char B, char C);

int tot = 0;

int main() {
	int n;
	scanf("%d",&n);
	hanoi(n, 'A', 'B', 'C');
	return 0;
}

void printMove(int x, char A, char B) {
    printf("%d: %d %c -> %c\n",++tot, x, A, B);
}

void hanoi(int x,char A, char B, char C) {
    if (x == 1) {
        printMove(x, A, C);
    }
    else {
        hanoi(x - 1, A, C, B);
        printMove(x, A, C);
        hanoi(x - 1, B, A, C);
    }
}
