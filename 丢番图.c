#include <stdio.h>
#include <stdlib.h>
int main()
{
	int f;
    for(f=0;f<=140;f++)
    {
    if(f/6+f/12+f/7+5+f/2+4==f && f%84==0)
    printf("%d\n",f-4);
    }
	system("pause");
	return 0;
}
