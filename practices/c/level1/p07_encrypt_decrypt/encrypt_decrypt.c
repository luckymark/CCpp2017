#include<stdio.h>
void encrypt(void);
void decrypt(void);
int main(void)
{
	char judge;
	printf("1.encrypt  2.decrypt  q.quit\n");
	while((judge=getch())!='q')
	{
		switch(judge)
		{
			case '1':
				system("cls");
				printf("mode encrypt:\n");
				encrypt();
				break;
			case '2':
				system("cls");
				printf("mode decrypt:\n");
				decrypt();
				break;
			case 'q':
				return 0;
			default:
				printf("error\n");
				system("pause");
		}
		system("cls");
		printf("1.encrypt  2.decrypt  q.quit\n");
	}
	
	return 0;
}
void encrypt(void)
{
	char ch1;
	while((ch1=getchar())!=EOF)
	{
		if((ch1>=65&&ch1<=87)||(ch1>=97&&ch1<=119))
		{
			putchar(ch1+3);
		}
		else if(ch1>87&&ch1<=90)
		{
			putchar(64+(ch1-87));
		}
		else if(ch1>119&&ch1<=122)
		{
			putchar(96+(ch1-119));
		}
		else if(ch1=='\n')
		{
			putchar('\n');
		}
		else
		{
			putchar(' ');
		}
	}
}
void decrypt(void)
{
	char ch2;
	while((ch2=getchar())!=EOF)
	{
		if((ch2>=68&&ch2<=90)||(ch2>=100&&ch2<=122))
		{
			putchar(ch2-3);
		}
		else if(ch2>64&&ch2<=67)
		{
			putchar(87+ch2-64);
		}
		else if(ch2>96&&ch2<=99)
		{
			putchar(119+ch2-96);
		}
		else if(ch2=='\n')
		{
			putchar(ch2);	
		}
		else
		{
			putchar(' ');
		}
	}
}
