#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 1000
#define MAXPASSWD 100
void encrypt(char text[]);
void decrypt(char text[]);
void getStr(char s[]);
int equalStr(char s1[],char s2[]);
/* <string.h> is required to use this function */

int main()
{	
	int i;
	char c;
	char text[MAXLINE];
	char passwd[MAXPASSWD];
	char confirm[MAXPASSWD];

	printf("\nEnter the text to be encrypt: ");
	getStr(text);
	do {
	printf("\nEnter your password: ");
	getStr(passwd);
	printf("\nConfirm your password: ");
	getStr(confirm);
	if (equalStr(passwd,confirm))	break;	
	printf("\nDifferent!\n");	}
	while (1);

	encrypt(text);

	printf("\nWould you like to see your text after encrypt?\n");
	puts("Press 'y' as yes.");
	if ((c = getchar()) == 'y' || c == 'Y')
	{	printf("%s\n",text);	}

	getchar();
	for (i = 3; i >= 1; i--)
	{	puts("Enter your passward to decrypt your text: ");
		getStr(confirm);
		if (equalStr(passwd,confirm))	break;	
		puts("Incorrect passward!");	}
	if (i > 0)
	{	decrypt(text);
		printf("\n%s\n",text);	}
	else	
	{	puts("You've run out of three chances, bye!");	}
}
	


void getStr(char s[])
{	
	int i;
	for (i = 0; (s[i] = getchar()) != '\n'; i++)
		;
	s[i] = '\0';
}



int equalStr(char s1[],char s2[])
{
	assert(s1[0] != '\0');
	int i;
	if (strlen(s1) == strlen(s2))
	{	for (i = 0; s1[i] != '\0'; i++) 
		{	if (s1[i] != s2[i])	break;	}	}
	if (s1[i] == '\0')	return 1;
	else return 0;
}



void encrypt(char text[])
{	
	int i;
	for (i = 0; text[i] != '\0'; i++)
	{	text[i] = ~text[i];	}
}



void decrypt(char text[])
{	
	encrypt(text);	
}
