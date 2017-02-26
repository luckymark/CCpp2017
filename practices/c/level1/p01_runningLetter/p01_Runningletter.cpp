#include <stdio.h>
#include <string.h>
#include <windows.h>
 
int main()
{
    char c;
    scanf ("%c", &c);
    int i,j;
    system("mode con cols=16 lines=9");
    int width = GetSystemMetrics ( SM_CXSCREEN );
    for (i = 0; i < 16; i++)
    {
        system ("cls");
        for (j = 0; j < i; j++)
        {
            printf (" ");
        }
        printf ("%c", c);
        Sleep (100);
    }
    for(i = 15; i >= 0; i--)
    {
    	system ("cls");
    	for (j = 0; j < i; j++)
    	{
		    printf (" ");
		}
		printf ("%c", c);
		Sleep (100);
		printf ("\n");
	}
    return 0;
}
