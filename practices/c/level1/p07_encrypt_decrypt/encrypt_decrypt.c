#include <stdio.h>
 
void encrypt(char*);
void decrypt(char*);

int main() 
{
	char a[10000];
    char choice;
	printf("D:decrypt E:encrypt\n");
    scanf("%c",&choice);
    if(choice=='D'||choice=='d')
    {
        printf("Text:");
        scanf("%s",a);
        encrypt(a);
        printf("%s\n",a);
    }
	else if(choice=='E'||choice=='e')
    {
        printf("Encrypted text:");
        scanf("%s",a);
        decrypt(a);
        printf("%s\n",a);
    }
    else
    {
        printf("Wrong input.");
    }
}

void encrypt(char* str)
{
    char *ch=str;
    while(*ch!='\0')
    {
        *(ch)^='#';
        ++*(ch);
        ++ch;
    }
}

void decrypt(char* str)
{
    char *ch=str;
    while(*ch!='\0')
    {
        --*(ch);
        *(ch)^='#';
        ++ch;
    }
}