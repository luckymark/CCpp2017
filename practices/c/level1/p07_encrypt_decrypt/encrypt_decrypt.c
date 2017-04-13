#include <stdio.h>
#include <string.h>
char s[50000];
void encrypt();
void decrypt();
int main()
{
	scanf("%s", s);
	encrypt();
	printf("%s\n", s);
	decrypt();
	printf("%s\n", s);
	return 0;
}
void encrypt()
{
	int i;
	for (i = 0; i < strlen(s); i++)
		s[i] += 5;
}
void decrypt()
{
	int i;
	for (i = 0; i < strlen(s); i++)
		s[i] -= 5;
}
