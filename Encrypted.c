#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

void Encrypte(char* p)
{
	int i = 0;
	while (p[i] != '\0')
	{
		p[i] = p[i] + '3' - '1';
		printf("%c", p[i]);
		i++;
	}
	printf("\n");
}

void Decrypte(char* p)
{
	int i = 0;
	while (p[i] != '\0')
	{
		p[i] = p[i] - '3' + '1';
		printf("%c", p[i]);
		i++;
	}
	printf("\n");
}

int main()
{
	char p[10000];
	int Judge = 0;
	printf("Please input the string need opreating\n");
	scanf("%s", p);
	printf("En or De?\nPleaes input 1(En) or 2(De)\n");
	scanf("%d", &Judge);
	if (Judge == 1)
	{
		Encrypte(p);
	}
	else if (Judge == 2)
	{
		Decrypte(p);
	}
	else
	{
		printf("Input Error!");
		return -1;
	}
    return 0;
}

