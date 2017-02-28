#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i;
	for(i=100;i<=999;i++)
    {
    if((i%10)*(i%10)*(i%10)+(i/100)*(i/100)*(i/100)
    +((i/10)%10)*((i/10)%10)*((i/10)%10) == 100*(i/100)+
    10*((i/10)%10)+i%10)
    printf("%d\t",i);
    }
    	system("pause");
	return 0;
}
