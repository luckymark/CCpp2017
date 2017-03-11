#include <stdio.h>
#include <stdlib.h>
int main()
{
	int units, tens, hundreds;
	for (int i = 100; i < 999; i++)
	{
		hundreds = i / 100;
		tens = i / 10 %10;
		units = i % 100 %10;
		if (i == hundreds*hundreds*hundreds + tens*tens*tens + units*units*units)
			printf("%d ", i);
	}
		system("pause");
		return 0;
}
