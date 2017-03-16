#include <stdio.h>

int check(int n);

int main() {
    for (int i = 1; i <= 1000; i++) {
        if (check(i)) printf("%d ",i - 4);
    }
    return 0;
}

int check(int n) {
    if (n%6 != 0 || n%12 != 0 || n%7 !=0) return 0;
    int x = n/6 + n/12 + n/7 + 5;
    int ageSon = n - x - 4;
    return n == ageSon * 2;
}
