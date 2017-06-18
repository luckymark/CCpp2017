#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void Goldbach();

int main()
{	
	Goldbach();
	system("pause");
	return 0;
}

void Goldbach() {
	int mark_prime1 = 0, mark_prime2 = 0;
	for (int i = 2; i <= 100; i = i + 2)
		for (int j = 2; j < i; j++)
		{
			for (int k = 2; k <= sqrt(j); k++)
			{
				mark_prime1 = 0;
				if (j%k == 0)
				{
					mark_prime1 = 1;
					break;
				}

			}
			if (mark_prime1 == 0)
			{
				int ano_pri = i - j;
				for (int k = 2; k <= sqrt(ano_pri); k++)
				{
					mark_prime2 = 0;
					if (ano_pri%k == 0)
					{
						mark_prime2 = 1;
						break;
					}
				}
				if (mark_prime2 == 0)
				{
					printf("%d+%d=%d ", j, ano_pri, i);
				}

			}
		}
}
