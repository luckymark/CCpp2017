#include <stdio.h>
#include <string.h>
char s[100000];
void encrypt()
{
    int i;
    for (i = 0; i < strlen(s); i++)
        s[i] += 1;
}
void decrypt()
{
    int i;
    for (i = 0; i < strlen(s); i++)
        s[i] -= 1;
}
int main()
{
    scanf("%s", s);
    encrypt();
    printf("%s\n", s);
    decrypt();
    printf("%s\n", s);
    return 0;
}
