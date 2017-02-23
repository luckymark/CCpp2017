#include<stdio.h>
#include<windows.h>
void running(int col);
int main(void)
{
	system("mode con cols=63");
	running(63);
	
	return 0;
} 
void running(int col)
{
	int i,j;
	while(1)
	{
		for(i=0;i<=col-1;i++)
		{
			Sleep(50);
			system("cls");
			for(j=0;j<i;j++)
			{
				printf(" ");
			}
			putchar('>');
	    }
		for(i=col-1;i>=0;i--)
		{
			Sleep(50);
			system("cls");
			for(j=0;j<i;j++)
			{
				printf(" ");
			}
			putchar('<');
	    }	    
	}
}
