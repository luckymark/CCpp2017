#include <stdio.h>

void hanoi(int n, char from, char to, char depend_on)
{
    if (n > 1)
    {
        hanoi(n - 1, from, depend_on, to);
        printf("%c->%c\n", from, to);
        hanoi(n-1, depend_on, to, from);
    }
    else
    {
        printf("%c->%c\n", from, to);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0; 
}