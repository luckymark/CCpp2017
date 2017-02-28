#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main()
{int i,j;
system("mode con cols=70");
	for(i=0;i<=70;i++)
    {
      system("cls");
    for(j=0;j<i;j++)
    {
    printf(" ");
    }
    printf("*");
    Sleep(1);
	}
    if(i==71)
    {
    for(i=70;i>=0;i--)
    {
    system("cls");
    for(j=0;j<i;j++)
    {
    printf(" ");
    }
    printf("*");
      Sleep(1);
	}
    }
    
    
    
	system("pause");
	return 0;
}
