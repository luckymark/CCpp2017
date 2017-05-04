#include <stdio.h>

double exchangeRMB(int USD)
{
	return USD*6.9;
}

int main()
{
	int USD=1;
	printf("%f",exchangeRMB(USD));
	
	return 0;
}
