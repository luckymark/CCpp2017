#include <stdio.h>
#define N 64
void dfs(int n, int a, int b, int c) {
    if (n == 1)
    {
        printf("%c-->%c\n", a, c);
        return;
    }
    dfs(n - 1, a, c, b);
    printf("%c-->%c\n", a, c);
    dfs(n - 1, b, a, c);
}

int main() {
    dfs(N, 'A', 'B', 'C');
    return 0;
}
