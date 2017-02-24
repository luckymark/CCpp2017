#include <stdio.h>
#include <time.h>
#include <windows.h>
int main()
{
	char c='a';
	int n=20;
	while(true)
	{
			for(int i=0;i<n;i++)
		{
			system("cls");
			for(int j=0;j<i;j++)
			{
				printf(" ");
			}
			printf("%c\n",c);
			
			int now=clock();
			for(;clock()-now<CLOCKS_PER_SEC/10;);
		}
		
		for(int i=0;i<n;i++)
		{
			system("cls");
			for(int j=n-1;j>i;j--)
			{
				printf(" ");
			}
			printf("%c\n",c);
			
			int now=clock();
			for(;clock()-now<CLOCKS_PER_SEC/10;);
		}
	}
	
}





























