#include <cstdio>
#include <cstring>
char s[100000];
void encrypt()
{
    for(int i=0;i<strlen(s);i++)s[i]+=1;
}
void decrypt()
{
    for(int i=0;i<strlen(s);i++)s[i]-=1;
}
int main()
{
    scanf("%s",s);
    encrypt();
    printf("%s\n",s);
    decrypt();
    printf("%s\n",s);
    return 0;
}
