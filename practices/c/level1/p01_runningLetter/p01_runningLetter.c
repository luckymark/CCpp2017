#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#define N 20

char ch[N];

void runLetter(int n) {
    system("clear");
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
    puts(ch);
	usleep(50000);
}

int checkRight(int t) {
    return t <= 80 - strlen(ch);
}

int checkLeft(int t) {
    return t >= 0;
}

int main() {
    printf("Input the word or letter:\n");
	gets(ch);
    while (1) {
        int t = 0;
        while (checkRight(t)) {
            runLetter(t++);
        }
        while (checkLeft(--t)) {
            runLetter(t);
        }
    }
}
