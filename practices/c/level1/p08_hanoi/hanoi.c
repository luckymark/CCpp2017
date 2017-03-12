#include <stdio.h>
#define n 64

char ch[3];
int num[3];
void dfs(int x, int y, int z) {
    if (num[x] == 1)
    {
        printf("%c-->%c\n", ch[x], ch[z]);
        num[x]--; num[z]++;
        return;
    }
    num[x]--;
    dfs(x, z, y);
    printf("%c-->%c\n", ch[x], ch[z]);
    num[z]++;
    dfs(y, x, z);
}

int main() {
    num[0] = n; num[1] = 0; num[2] = 0;
    ch[0] = 'A'; ch[1] = 'B'; ch[2] = 'C';
    dfs(0, 1, 2);
    return 0;
}
