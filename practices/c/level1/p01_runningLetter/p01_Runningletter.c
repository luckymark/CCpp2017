#include <stdio.h>
#include <string.h>
#include <windows.h>
 
int main()
{
    char c;
    scanf("%c", &c);
    system("mode con cols=16 lines=9");
    int width = GetSystemMetrics ( SM_CXSCREEN );
    for (int i = 0; i < 32; i++)
    {
        system("cls");
        if(i<16)
        {
            for(int j = 0; j < i; j++)
            {
                printf(" ");
            }
            printf("%c", c);
            Sleep(100);
        }
        else
        {
            for (int j = 0; j < 31 - i; j++)
    	    {
		        printf (" ");
		    }
		    printf ("%c", c);
		    Sleep (100);
		    printf ("\n");
	    }
    }
    return 0;
}
