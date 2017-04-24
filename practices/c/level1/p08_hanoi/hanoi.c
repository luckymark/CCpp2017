#include <stdio.h>
#define n 64
char ch[3];
void dfs(int x, int y, int z, int num) {
    if (num == 1)
    {
        printf("%c-->%c\n", ch[x], ch[z]);
        return;
    }
    dfs(x, z, y, num - 1);
    printf("%c-->%c\n", ch[x], ch[z]);
    dfs(y, x, z, num - 1);
}

int main() {
    ch[0] = 'A'; ch[1] = 'B'; ch[2] = 'C';
    dfs(0, 1, 2, n);
    return 0;
}
