#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n = 0;
	printf("Please input n:");
	scanf("%d",&n);

	if (0==n%13)
		printf("%d ��13�ı���",n);
	else
		printf("%d ����13�ı���",n);

	return 0;
}
