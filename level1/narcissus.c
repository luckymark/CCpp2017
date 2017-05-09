#include <stdio.h>

int main()
{
	int i,ones,tens,hundreds;
	for (i=100; i<1000; i++){
		ones = i % 10;
		tens = i/10 %10;
		hundreds = i/100;
		if (ones*ones*ones + tens*tens*tens + hundreds*hundreds*hundreds == i)
			printf("%7d\n",i);
	}
	return 0;
}
