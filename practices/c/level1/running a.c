#include <stdio.h>
#include <windows.h>

int main()
{
    int i,j;
    for (i=0;i<31;i++)
    {
        system("cls");
        for(j=0;j<i;j++)
        {
            printf(" ");
        }
        printf("a");
        Sleep(100);
    }
    
	for(i =30;i>= 0;i--)
    {
    	system("cls");
    	for(j=0; j<i;j++)
    	{
		    printf(" ");
		}
		printf("a");
		Sleep(100);
	}
}
