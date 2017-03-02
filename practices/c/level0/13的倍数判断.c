#include <stdio.h>

int main(void)
{
	int n = 0;
	printf("Please input n:");
	scanf("%d",&n);

	if (0==n%13)
		printf("%d ÊÇ13µÄ±¶Êý",n);
	else
		printf("%d ²»ÊÇ13µÄ±¶Êý",n);

	return 0;
}
