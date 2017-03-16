#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define WIDTH 89
#define SPACE 50
char s[10000];
int k = 0, f = 1;
int main()
{
    int i;
    for (i = 0; i <= WIDTH; i++)
    {
        s[i] = ' ';
    }
    while (1)
    {
        s[k] = 'R';
        printf("%s", s);
        s[k] = ' ';
        if (f > 0)
        {
            k++;
        }
        else
        {
            k--;
        }
        Sleep(SPACE);
        system("cls");
        if (k == WIDTH || k == 0)
        {
            f = -f;
        }
    }
    return 0;
}
