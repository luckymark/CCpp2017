#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n = 0;
	printf("Please input n:");
	scanf("%d",&n);

	if (0==n%13)
		printf("%d 是13的倍数",n);
	else
		printf("%d 不是13的倍数",n);

	return 0;
}
