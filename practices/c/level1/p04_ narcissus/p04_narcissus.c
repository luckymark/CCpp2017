#include <stdio.h>

int Power(int x);
int narcissusChange(int n);

int main() {
    for (int i = 100; i < 1000; i++) {
        if (i == narcissusChange(i)) printf("%d\t",i);
    }
    return 0;
}

int Power(int x) {
    return x*x*x;
}

int narcissusChange(int n) {
    int ans = 0;
    while (n) {
        ans += Power(n%10);
        n = n/10;
    }
    return ans;
}
