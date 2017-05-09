#include <stdio.h>
#include <conio.h>
char encrypt ();
char decrypt ();

int main()
{
	encrypt();
	decrypt();
}

char encrypt ()
{
	char ch ;
	printf("输入明文：\n"); 
	while((ch=getchar())!='\n')
	{	
		putchar(ch+1);
	}
}

char decrypt ()
{
	char ch ;
	printf("输入密文：\n");
	while((ch=getchar())!='\n')
	{
		putchar(ch-1);
	}
	
}
