#include<stdio.h>

int main(void)
{
	float i;
	for(i = 0; i < 150; i++)
	{
		if((i / 6 + i / 12 + i / 7 + 5 + i / 2 + 4) == i)
		{
		    printf ("When Diophantus's son dead, Diophantus's age is %g", i - 4);
		    break;
	    }
	}
	return 0;
} 
