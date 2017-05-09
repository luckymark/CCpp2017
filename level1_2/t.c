#include <stdio.h>

main()
{
	char str[10];
	int i;
	for (i = 0; i < 10; i++)	str[i] = getchar();
	printf("\n%s\n",str);
	for (i = 0; i < 10; i++)	putchar(str[i]);
	putchar('\n');
}
