#include <stdio.h>
int main(void)
{
	int i,j;
	printf("          "); 
	for (i=1;i<10;i++)
	printf("%-11d",i);
	printf("\n"); 
	for (i=1;i<10;i++){
		printf("%-10d",i);
		for (j=1;j<=i;j++){
		    printf("%d¡Á%d=%d    ",i,j,i*j);}
		printf("\n");
			}
	}
