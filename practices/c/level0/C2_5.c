#include <stdio.h>
int main()
{
    int n;
    for(n=1;n<101;n++)
    {
	    if(n%3==0&&n%5!=0)
		{
			printf("%d\t",n);
		}	
	}
    return 0;
}
