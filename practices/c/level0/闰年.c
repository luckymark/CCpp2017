#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int year = 0;
	printf("Please input year:");
	scanf("%d",&year);

	if ((0 != year % 100 && 0 == year % 4) || 0 == year % 400)

        printf("%d is leap year",year);
    else
        printf("%d 不是闰年",year);

	return 0;
}
