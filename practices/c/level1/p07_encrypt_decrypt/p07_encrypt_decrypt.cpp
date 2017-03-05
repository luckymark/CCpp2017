#include<stdio.h>
#include<string.h>

int main()
{
	int i, n, command;
	char text[256] = {'\0'}, encryption[256] = {'\0'};  
	printf("Plz enter your command.\n");
	printf("1.Encrypt\n");
	printf("2.Decrypt\n");
	printf("3.Exit\n");
	scanf("%d", &command);
	if(command == 1)
	{
		printf("Plz enter the words you want to encrypt.\n");
		scanf("%s", &text);
		n = strlen(text);
		for(i = 0; i < n; i++)
		encryption[i] = text[i] + i + 6;
		encryption[i] = '\0';
		printf("Encrypt words are %s.\n", encryption);
	}
	else if(command == 2)
	{
		printf("Plz enter the words you want to decrypt.\n");
		scanf("%s", &encryption);
		n = strlen(encryption);
		for(i = 0; i < n; i++)
		text[i] = encryption[i] - i - 6;
		text[i] = '\0';
		printf("Decrypt words are %s.\n", text);
	}
	else if(command == 3)
	return 0;
	else
	printf("Wrong command,plz try again.\n");
}
