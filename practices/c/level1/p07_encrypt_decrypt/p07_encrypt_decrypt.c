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
	printf("�������ģ�\n"); 
	while((ch=getchar())!='\n')
	{	
		putchar(ch+1);
	}
}

char decrypt ()
{
	char ch ;
	printf("�������ģ�\n");
	while((ch=getchar())!='\n')
	{
		putchar(ch-1);
	}
	
}
