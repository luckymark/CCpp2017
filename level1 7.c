//vigenere cipher
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define x "plaintext"
#define y "key"
#define z "ciphertext"
char select();
void encryption();
void decryption();
int main()
{
	
	
	while (1)
	{
	char ch = select();
		
		switch (ch)
		{
			case'a':printf("let's go to encryption\n");
			{
				encryption();
				break; 
			}
			case'b':printf("let's go to decryption\n");
			{
				decryption();
				break; 
			}
			case'q':return 0;
			default:
			{
				printf("try again\n");
				continue;
			}

								
		}
	}
	system("pause");
	return 0;
}
char select()
{
	int ch;
	printf("make a choice\n"
		"a encryption    b decryption\n"
		"q quit\n");
	ch = getchar();
	while (getchar() != '\n')
		continue;
	return ch;
}

void encryption()
{
	char text[101] = "\0", key[101];
	printf("please input %s:", x);
	gets(text);
	for (int i = 0; i < strlen(text); i++)//input a b,change into lower case
	{
		text[i] = tolower(text[i]);
	}

	printf("please input %s:", y);
	gets(key);
	for (int i = 0; i < strlen(key); i++)
	{
		key[i] = tolower(key[i]);
	}
	if (strlen(text) < strlen(key))
	{
		printf("key is longer than plaintext\n");
		return ;
	}
	
	for (int i = 0,j = 0; text[i]; i++)
	{
		if (text[i] >= 'a'&&text[i] <= 'z')
		{
			text[i] = 'a' + (text[i] + (key[j%strlen(key)] - 'a') - 'a') % 26;
			j++;
		}
	}
	
	printf("ciphertext");
	puts(text);
	
}
void decryption()
{
	char text[101] = "\0", key[101];
	printf("please input %s:", z);
	gets(text);
	for (int i = 0; i<strlen(text); i++)//input a b,change into lower case
		text[i] = tolower(text[i]);

	printf("please input %s:", y);
	gets(key);
	for (int i = 0; i <strlen(key); i++)
		key[i] = tolower(key[i]);
	if (strlen(text) < strlen(key))
	{
		printf("key is longer than plaintext\n");
		return;
	}

	for (int i = 0, j = 0; text[i]; i++)
	{
		if (text[i] >= 'a'&&text[i] <= 'z')
		{
			text[i] = 'a' + (text[i] - (key[j%strlen(key)] - 'a') + 26-'a') % 26;
			j++;
		}
	}
	printf("plaintext");
	puts(text);
}
