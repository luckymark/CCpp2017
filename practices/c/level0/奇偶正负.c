#include <stdio.h>

int main(void)
{
    int n = 0;
    
    printf("Please input n:");
    scanf("%d",&n);

    if (n>0)
        printf("%d is positive number\n",n);
    else if (n<0)
        printf("%d is negative number\n",n);
    else
        printf("%d is zero\n",n);

    if (0 == n % 2)
        printf("%d is a even\n",n);
    else
        printf("%d is a obb\n",n);

    return 0;
}
