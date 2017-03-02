#include <stdio.h>
int main(void)
{
	int i,sum=0;
	for (i=1;i<=100;i++){
		if ((i+3)%10==0){
		    sum+=i;
		    printf("%5d",i);
		}
	    else if (i%7==0){
	        sum+=i;
	        printf("%5d",i);
	   }
	}
	printf("\n这些数的总和是%d",sum);
 } 
